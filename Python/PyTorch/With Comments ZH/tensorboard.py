import torch
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
from PIL import Image
from torchvision import transforms
from torchvision import models,datasets
from tensorboardX import SummaryWriter
# from torch.utils.tensorboard import SummaryWriter

# 在使用前请先去确认执行tensorboard --logdir logs 并保证 http://localhost:6006/ 页面能够正常打开

cat_img = Image.open('./1280px-Felis_silvestris_catus_lying_on_rice_straw.jpg')
cat_img.size

transform_224 = transforms.Compose([
        transforms.Resize(224), # 这里要说明下 Scale 已经过期了，使用Resize
        transforms.CenterCrop(224),
        transforms.ToTensor(),
    ])
cat_img_224=transform_224(cat_img)

# 将图片展示在tebsorboard中：
writer = SummaryWriter(log_dir='./logs', comment='cat image') # 这里的logs要与--logdir的参数一样
writer.add_image("cat",cat_img_224)
writer.close()# 执行close立即刷新，否则将每120秒自动刷新

# 浏览器访问 http://localhost:6006/#images 即可看到猫的图片

# 更新损失函数和训练批次我们与visdom一样使用模拟展示，这里用到的是tensorboard的SCALAR页面

x = torch.FloatTensor([100])
y = torch.FloatTensor([500])

for epoch in range(30):
    x = x * 1.2
    y = y / 1.1
    loss = np.random.random()
    with SummaryWriter(log_dir='./logs', comment='train') as writer: #可以直接使用python的with语法，自动调用close方法
        writer.add_histogram('his/x', x, epoch)
        writer.add_histogram('his/y', y, epoch)
        writer.add_scalar('data/x', x, epoch)
        writer.add_scalar('data/y', y, epoch)
        writer.add_scalar('data/loss', loss, epoch)
        writer.add_scalars('data/data_group', {'x': x,
                                                'y': y}, epoch)

# 浏览器访问 http://localhost:6006/#scalars 即可看到图形

# PROJECTOR的的原理是通过PCA，T-SNE等方法将高维向量投影到三维坐标系（降维度）。
# Embedding Projector从模型运行过程中保存的checkpoint文件中读取数据，默认使用主成分分析法（PCA）将高维数据投影到3D空间中，
# 也可以通过设置设置选择T-SNE投影方法，这里做一个简单的展示。

BATCH_SIZE=512 
EPOCHS=20 
train_loader = torch.utils.data.DataLoader(
        datasets.MNIST('data', train=True, download=True, 
                       transform=transforms.Compose([
                           transforms.ToTensor(),
                           transforms.Normalize((0.1307,), (0.3081,))
                       ])),
        batch_size=BATCH_SIZE, shuffle=True)


class ConvNet(nn.Module):
    def __init__(self):
        super().__init__()
        # 1,28x28
        self.conv1=nn.Conv2d(1,10,5) # 10, 24x24
        self.conv2=nn.Conv2d(10,20,3) # 128, 10x10
        self.fc1 = nn.Linear(20*10*10,500)
        self.fc2 = nn.Linear(500,10)
    def forward(self,x):
        in_size = x.size(0)
        out = self.conv1(x) #24
        out = F.relu(out)
        out = F.max_pool2d(out, 2, 2)  #12
        out = self.conv2(out) #10
        out = F.relu(out)
        out = out.view(in_size,-1)
        out = self.fc1(out)
        out = F.relu(out)
        out = self.fc2(out)
        out = F.log_softmax(out,dim=1)
        return out
model = ConvNet()
optimizer = torch.optim.Adam(model.parameters())

def train(model, train_loader, optimizer, epoch):
    n_iter=0
    model.train()
    for batch_idx, (data, target) in enumerate(train_loader):
        optimizer.zero_grad()
        output = model(data)
        loss = F.nll_loss(output, target)
        loss.backward()
        optimizer.step()
        if(batch_idx+1)%30 == 0: 
            n_iter=n_iter+1
            print('Train Epoch: {} [{}/{} ({:.0f}%)]\tLoss: {:.6f}'.format(
                epoch, batch_idx * len(data), len(train_loader.dataset),
                100. * batch_idx / len(train_loader), loss.item()))
            #相对于以前的训练方法 主要增加了以下内容
            out = torch.cat((output.data, torch.ones(len(output), 1)), 1) # 因为是投影到3D的空间，所以我们只需要3个维度
            with SummaryWriter(log_dir='./logs', comment='mnist') as writer: 
                #使用add_embedding方法进行可视化展示
                writer.add_embedding(
                    out,
                    metadata=target.data,
                    label_img=data.data,
                    global_step=n_iter)

# 这里节省时间，只训练一次
train(model, train_loader, optimizer, 0)
# 打开 http://localhost:6006/#projector 即可看到效果。

