import torch
import torch.nn as nn
import torch.nn.functional as F

# torch.nn是专门为神经网络设计的模块化接口。nn构建于 Autograd之上，可用来定义和运行神经网络。
# 只要继承nn.Module，并实现它的forward方法，PyTorch会根据autograd，自动实现backward函数，
# 在forward函数中可使用任何tensor支持的函数，还可以使用if、for循环、print、log等Python语法，写法和标准的Python写法一致。

# 定义一个网络
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(1, 6, 3)
        self.fc1 = nn.Linear(1350, 10)
    def forward(self, x):
        print(x.size())
        x = self.conv1(x)
        x = F.relu(x)
        print(x.size())
        x = F.max_pool2d(x, (2, 2))
        x = F.relu(x)
        print(x.size())
        x = x.view(x.size()[0], -1)
        print(x.size())
        x = self.fc1(x)
        return x

net = Net()
print(net)

# 网络的可学习参数通过net.parameters()返回
for parameter in net.parameters():
    print(parameter)

# net.named_parameters可同时返回可学习的参数及名称。
for name, parameter in net.named_parameters():
    print(name, ': ', parameter.size())

# forward函数的输入和输出都是Tensor
x = torch.randn(1, 1, 32, 32)
out = net(x)
print(out.size())
print(x.size())

# 在反向传播前，先要将所有参数的梯度清零
net.zero_grad()
out.backward(torch.ones(1, 10))

# 在nn中PyTorch还预制了常用的损失函数，下面我们用MSELoss用来计算均方误差
y = torch.arange(0, 10).view(1, 10).float()
criterion = nn.MSELoss()
loss = criterion(out, y)
print(loss.item())

# 优化器
import torch.optim
inpu = torch.randn(1, 1, 32, 32)
out = net(inpu)
criterion = nn.MSELoss()
loss = criterion(out, y)
# 新建优化器
optimizer = torch.optim.SGD(net.parameters(), lr=0.01)

# 梯度清零
optimizer.zero_grad()

# 求导
loss.backward()

# 更新参数
optimizer.step()