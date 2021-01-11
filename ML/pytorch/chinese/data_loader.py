from torch.utils.data import Dataset, DataLoader
import pandas as pd

# Dataset是一个抽象类，为了能够方便的读取，需要将要使用的数据包装为Dataset类。 自定义的Dataset需要继承它并且实现两个成员方法：
class MyDataset(Dataset):
    def __init__(self, csv_file):
        self.df = pd.read_csv(csv_file)
    def __len__(self):
        return len(self.df)
    def __getitem__(self, idx):
        return self.df.iloc[idx].SalePrice

my_demo = MyDataset("my.csv")
# len
print(len(my_demo))
# get item
print(my_demo[0])

# DataLoader为我们提供了对Dataset的读取操作，
# 常用参数有：batch_size(每个batch的大小)、 shuffle(是否进行shuffle操作)、 num_workers(加载数据的时候使用几个子进程)。
dl = DataLoader(my_demo, batch_size=32, shuffle=True, num_workers=0)

# DataLoader返回的是一个可迭代对象，我们可以使用迭代器分次获取数据
my_iter = iter(dl)
print(next(my_iter))

# 常见的用法是使用for循环对其进行遍历
for i, data in enumerate(dl):
    print(i, data)
    break

# torchvision 是PyTorch中专门用来处理图像的库，PyTorch官网的安装教程中最后的pip install torchvision 就是安装这个包。
# torchvision.datasets 可以理解为PyTorch团队自定义的dataset，这些dataset帮我们提前处理好了很多的图片数据集，我们拿来就可以直接使用：
# MNIST
# COCO
# Captions
# Detection
# LSUN
# ImageFolder
# Imagenet-12
# CIFAR
# STL10
# SVHN
# PhotoTour
import torchvision.datasets as datasets
trainset = datasets.MNIST(root="./data", train=True, download=True, transform=None)

# torchvision不仅提供了常用图片数据集，还提供了训练好的模型，可以加载之后，直接使用，或者在进行迁移学习 
# torchvision.models模块的 子模块中包含以下模型结构。
# AlexNet
# VGG
# ResNet
# SqueezeNet
# DenseNet
import torchvision.models as models
resnet = models.resnet101(pretrained=True)

# transforms 模块提供了一般的图像转换操作类，用作数据处理和数据增强
import torchvision.transforms as transforms
transform = transforms.Compose([transforms.RandomCrop(32, padding=4), 
    transforms.RandomHorizontalFlip(),
    transforms.RandomRotation(-45, 45),
    transforms.ToTensor(),
    transforms.Normalize((0.4914, 0.4822, 0.4465), (0.229, 0.224, 0.225))])
# (0.485, 0.456, 0.406), (0.2023, 0.1994, 0.2010) 这几个数字是什么意思？
# 官方的这个帖子有详细的说明: https://discuss.pytorch.org/t/normalization-in-the-mnist-example/457/21 
# 这些都是根据ImageNet训练的归一化参数，可以直接使用，我们认为这个是固定值就可以