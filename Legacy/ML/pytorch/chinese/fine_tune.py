import torch, torchvision, os
import torch.nn as nn
import torch.nn.functional as F
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader, Dataset
from torchvision import datasets, models, transforms
from PIL import Image
from sklearn.model_selection import StratifiedShuffleSplit

# 使用官方训练好的resnet50来参加kaggle上面的 dog breed 狗的种类识别来做一个简单微调实例
# https://www.kaggle.com/c/dog-breed-identification/
DATA_ROOT = 'data'
all_labels_df = pd.read_csv(os.path.join(DATA_ROOT,'labels.csv'))

# 获取狗的分类根据分类进行编号
# 这里定义了两个字典，分别以名字和id作为对应，方便后面处理
breeds = all_labels_df.breed.unique()
breed2idx = dict((breed,idx) for idx,breed in enumerate(breeds))
idx2breed = dict((idx,breed) for idx,breed in enumerate(breeds))
len(breeds)

# 添加到列表中
all_labels_df['label_idx'] = [breed2idx[b] for b in all_labels_df.breed]

# 由于我们的数据集不是官方指定的格式，我们自己定义一个数据集
class DogDataset(Dataset):
    def __init__(self, labels_df, img_path, transform=None):
        self.labels_df = labels_df
        self.img_path = img_path
        self.transform = transform
        
    def __len__(self):
        return self.labels_df.shape[0]
    
    def __getitem__(self, idx):
        image_name = os.path.join(self.img_path, self.labels_df.id[idx]) + '.jpg'
        img = Image.open(image_name)
        label = self.labels_df.label_idx[idx]
        
        if self.transform:
            img = self.transform(img)
        return img, label

# 定义一些超参数
IMG_SIZE = 224 # resnet50的输入是224的所以需要将图片统一大小
BATCH_SIZE= 256 #这个批次大小需要占用4.6-5g的显存，如果不够的化可以改下批次，如果内存超过10G可以改为512
IMG_MEAN = [0.485, 0.456, 0.406]
IMG_STD = [0.229, 0.224, 0.225]
CUDA=torch.cuda.is_available()
DEVICE = torch.device("cuda" if CUDA else "cpu")

# 定义训练和验证数据的图片变换规则
train_transforms = transforms.Compose([
    transforms.Resize(IMG_SIZE),
    transforms.RandomResizedCrop(IMG_SIZE),
    transforms.RandomHorizontalFlip(),
    transforms.RandomRotation(30),
    transforms.ToTensor(),
    transforms.Normalize(IMG_MEAN, IMG_STD)
])

val_transforms = transforms.Compose([
    transforms.Resize(IMG_SIZE),
    transforms.CenterCrop(IMG_SIZE),
    transforms.ToTensor(),
    transforms.Normalize(IMG_MEAN, IMG_STD)
])

# 我们这里只分割10%的数据作为训练时的验证数据
dataset_names = ['train', 'valid']
stratified_split = StratifiedShuffleSplit(n_splits=1, test_size=0.1, random_state=0)
train_split_idx, val_split_idx = next(iter(stratified_split.split(all_labels_df.id, all_labels_df.breed)))
train_df = all_labels_df.iloc[train_split_idx].reset_index()
val_df = all_labels_df.iloc[val_split_idx].reset_index()
print(len(train_df))
print(len(val_df))

# 使用官方的dataloader载入数据
image_transforms = {'train':train_transforms, 'valid':val_transforms}

train_dataset = DogDataset(train_df, os.path.join(DATA_ROOT,'train'), transform=image_transforms['train'])
val_dataset = DogDataset(val_df, os.path.join(DATA_ROOT,'train'), transform=image_transforms['valid'])
image_dataset = {'train':train_dataset, 'valid':val_dataset}

image_dataloader = {x:DataLoader(image_dataset[x],batch_size=BATCH_SIZE,shuffle=True,num_workers=0) for x in dataset_names}
dataset_sizes = {x:len(image_dataset[x]) for x in dataset_names}

# 开始配置网络，由于ImageNet是识别1000个物体，我们的狗的分类一共只有120，所以需要对模型的最后一层全连接层进行微调，将输出从1000改为120
model_ft = models.resnet50(pretrained=True) # 这里自动下载官方的预训练模型，并且
# 将所有的参数层进行冻结
for param in model_ft.parameters():
    param.requires_grad = False
# 这里打印下全连接层的信息
print(model_ft.fc)
num_fc_ftr = model_ft.fc.in_features #获取到fc层的输入
model_ft.fc = nn.Linear(num_fc_ftr, len(breeds)) # 定义一个新的FC层
model_ft=model_ft.to(DEVICE)# 放到设备中
print(model_ft) # 最后再打印一下新的模型

# 设置训练参数
criterion = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam([
    {'params':model_ft.fc.parameters()}
], lr=0.001)#指定 新加的fc层的学习率

# 定义训练函数
def train(model,device, train_loader, epoch):
    model.train()
    for batch_idx, data in enumerate(train_loader):
        x,y= data
        x=x.to(device)
        y=y.to(device)
        optimizer.zero_grad()
        y_hat= model(x)
        loss = criterion(y_hat, y)
        loss.backward()
        optimizer.step()
    print ('Train Epoch: {}\t Loss: {:.6f}'.format(epoch,loss.item()))

# 定义测试函数
def test(model, device, test_loader):
    model.eval()
    test_loss = 0
    correct = 0
    with torch.no_grad():
        for i,data in enumerate(test_loader):          
            x,y= data
            x=x.to(device)
            y=y.to(device)
            optimizer.zero_grad()
            y_hat = model(x)
            test_loss += criterion(y_hat, y).item() # sum up batch loss
            # pred = y_hat.max(1, keepdim=True)[1] # get the index of the max log-probability
            _, pred = torch.max(y_hat.data, 1)
            correct += pred.eq(y.view_as(pred)).sum().item()
    test_loss /= len(test_loader.dataset)
    print('\nTest set: Average loss: {:.4f}, Accuracy: {}/{} ({:.0f}%)\n'.format(
        test_loss, correct, len(val_dataset),
        100. * correct / len(val_dataset)))

# 训练9次，看看效果
for epoch in range(1, 10):
    train(model=model_ft,device=DEVICE, train_loader=image_dataloader["train"],epoch=epoch)
    test(model=model_ft, device=DEVICE, test_loader=image_dataloader["valid"])

# 每次训练都需要将一张图片在全部网络中进行计算，而且计算的结果每次都是一样的，这样浪费了很多计算的资源。
# 下面我们就将这些不进行反向传播或者说不更新网络权重参数层的计算结果保存下来，
# 这样我们以后使用的时候就可以直接将这些结果输入到FC层或者以这些结果构建新的网络层，省去了计算的时间
# 并且这样如果只训练全连接层，CPU就可以完成了。

# 固定层的向量导出
# 采用PyTorch比较高级的API，hook来处理了，我们要先定义一个hook函数
in_list= [] # 这里存放所有的输出
def hook(module, input, output):
    #input是一个tuple代表顺序代表每一个输入项，我们这里只有一项，所以直接获取
    #需要全部的参数信息可以使用这个打印
    #for val in input:
    #    print("input val:",val)
    for i in range(input[0].size(0)):
        in_list.append(input[0][i].cpu().numpy())

# 在相应的层注册hook函数，保证函数能够正常工作，我们这里直接hook 全连接层前面的pool层，获取pool层的输入数据，这样会获得更多的特征
model_ft.avgpool.register_forward_hook(hook)

# 开始获取输出，这里我们因为不需要反向传播，所以直接可以使用no_grad嵌套
with torch.no_grad():
    for batch_idx, data in enumerate(image_dataloader["train"]):
        x,y= data
        x=x.to(DEVICE)
        y=y.to(DEVICE)
        y_hat = model_ft(x)

features=np.array(in_list)
np.save("features",features)

# 这样再训练时我们只需将这个数组读出来，然后可以直接使用这个数组再输入到linear或者我们前面讲到的sigmod层就可以了。
# 我们在这里在pool层前获取了更多的特征，可以将这些特征使用更高级的分类器，例如SVM，树型的分类器进行分类。