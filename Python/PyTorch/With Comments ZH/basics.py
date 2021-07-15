import torch
from torch.nn import Linear, MSELoss
from torch.optim import SGD
import numpy as np

# 创建一个5x3矩阵，但是未初始化
x = torch.empty(5,3)

# 创建一个随机初始化的矩阵，0到1均匀分布
x = torch.rand(5, 3)

# 创建一个0填充的矩阵，数据类型为long
x = torch.zeros(5, 3, dtype=torch.long)

# 创建tensor并使用现有数据初始化
x = torch.tensor([1, 2, 3])

# 根据现有的张量创建张量。这些方法重用输入张量的属性，除非设置新的值进行覆盖
x = x.new_ones(5, 3, dtype=torch.long)
x = torch.randn_like(x, dtype=torch.float)

# 获取size，返回tuple类型
print(x.size())

# 加法
y = torch.rand(5, 3)
print(x + y)

# 加法2
print(torch.add(x, y))

# 加法，提供输出tensor作为参数
z = torch.empty(5, 3)
torch.add(x, y, out=z)

# 加法，替换原来张量
y.add_(x)

# numpy索引方式
print(x[:, 1])

# 改变张量维度和大小，类似numpy的reshape
x.view(3, 5)

# 只有一个元素的张量，得到python数据类型的数值，randn是均值0方差1的标准正态分布
x = torch.randn(1)
print(x.item())

# 所有tensor类型默认基于CPU，CharTensor类型不支持到numpy的转换
# 将一个torch tensor转换为numpy数组，tensor与numpy数组共享底层内存地址，修改一个会导致另一个的变化
a = torch.ones(5)
b = a.numpy()
a.add_(1)
# 此时a和b都是全部元素为2

# numpy array转换为torch tensor
a = np.ones(5)
b = torch.from_numpy(a)
np.add(a, 1, out=a)
# 此时a和b都是全部元素为2

# CUDA张量
# 判断是否有CUDA可用，将张量移动到指定的设备中
if torch.cuda.is_available():
    device = torch.device('cuda')
    y = torch.ones_like(x, device=device)
    x = x.to(device)
    z = x + y
    print(z.to('cpu', torch.double))

# autograd自动求导机制

# 如果设置 .requires_grad 为 True，那么将会追踪所有对于该张量的操作
# 当完成计算后通过调用 .backward()，自动计算所有的梯度， 这个张量的所有梯度将会自动积累到 .grad 属性。
# 要阻止张量跟踪历史记录，可以调用.detach()方法将其与计算历史记录分离，并禁止跟踪它将来的计算记录。

# 为了防止跟踪历史记录（和使用内存），可以将代码块包装在with torch.no_grad()：中。 
# 在评估模型时特别有用，因为模型可能具有requires_grad = True的可训练参数，但是我们不需要梯度计算。

# Tensor 和 Function互相连接并生成一个非循环图，它表示和存储了完整的计算历史。
# 每个张量都有一个.grad_fn属性，这个属性引用了一个创建了Tensor的Function（除非这个张量是用户手动创建的，即，这个张量的 grad_fn 是 None）。

# 如果需要计算导数，你可以在Tensor上调用.backward()。 
# 如果Tensor是一个标量（即它包含一个元素数据）则不需要为backward()指定任何参数， 但是如果它有更多的元素，你需要指定一个gradient 参数来匹配张量的形状。

# 创建一个张量并设置requires_grad=True来追踪她的计算历史
# x:(2, 2)
# z_i = 3/4(x_i+2)^2

x = torch.ones(2, 2, requires_grad=True)
# x.requires_grad_(True)
y = torch.add(x, 2)
z = y * y * 3
out = y.mean()
out.backward()
print(x.grad)
print(out.grad_fn)

# 一般来说，torch.autograd就是用来计算vector-Jacobian product的工具。
# l=g(f(x)), 根据链式法则，vector-Jacobian product 是 x 对 l 的梯度
x = torch.randn(3, requires_grad=True)
y = x * 2
while y.data.norm() < 1000:
    y = y * 2
print(y)
gradients = torch.tensor([0.1, 1.0, 0.0001], dtype=torch.float)
y.backward(gradients)
print(x.grad)

# 如果.requires_grad=True但是你又不希望进行autograd的计算， 那么可以将变量包裹在 with torch.no_grad()中:
with torch.no_grad():
    print((x**2).requires_grad)



x = np.random.rand(256)
noise = np.random.rand(256)/4
y = x * 5 + 7 + noise
model = Linear(1, 1)
criterion = MSELoss()
optimizer = SGD(model.parameters(), lr=0.01)
epochs = 3000
x_train = x.reshape(-1, 1).astype('float32')
y_train = y.reshape(-1, 1).astype('float32')

for i in range(epochs):
    # 整理输入和输出的数据，这里输入和输出一定要是torch的Tensor类型
    inp = torch.from_numpy(x_train)
    labels = torch.from_numpy(y_train)
    # 预测
    out = model(inp)
    # 损失
    loss = criterion(out, labels)
    # 求导
    optimizer.zero_grad()
    loss.backward()
    # 优化
    optimizer.step()
    # 隔一段时间打印损失
    if (i%100==0):
        print('epoch {}, loss {:1.4f}'.format(i,loss.data.item()))

[w, b] = model.parameters()
print(w.item(), b.item())

# 这里有一个重点：因为PyTorch是使用mini-batch来进行计算的，所以损失函数的计算出来的结果已经对mini-batch取了平均

# 常见（PyTorch内置）的损失函数有以下几个：
# nn.L1Loss
# 输入x和目标y之间差的绝对值，要求 x 和 y 的维度要一样  
# nn.NLLLoss
# 用于多分类的负对数似然损失函数, NLLLoss中如果传递了weights参数，会对损失进行加权   
# nn.MSELoss
# 均方损失函数 ，输入x和目标y之间均方差     
# nn.CrossEntropyLoss
# 多分类用的交叉熵损失函数，LogSoftMax和NLLLoss集成到一个类中，会调用nn.NLLLoss函数，
# 我们可以理解为CrossEntropyLoss()=log_softmax() + NLLLoss(), 因为使用了NLLLoss，所以也可以传入weight参数
# nn.BCELoss
# 计算 x 与 y 之间的二进制交叉熵
# 与NLLLoss类似，也可以添加权重参数：用的时候需要在该层前面加上 Sigmoid 函数。

# 随机梯度下降算法，带有动量（momentum）的算法作为一个可选参数可以进行设置，样例如下：
optimizer = torch.optim.SGD(model.parameters(), lr=0.1, momentum=0.9)
# 除了以上的带有动量Momentum梯度下降法外，RMSprop（root mean square prop）也是一种可以加快梯度下降的算法，
# 利用RMSprop算法，可以减小某些维度梯度更新波动较大的情况，使其梯度下降的速度变得更快
optimizer = torch.optim.RMSprop(model.parameters(), lr=0.01, alpha=0.99)
# Adam 优化算法的基本思想就是将 Momentum 和 RMSprop 结合起来形成的一种适用于不同深度学习结构的优化算法
# 这里的lr，betas，还有eps都是用默认值即可，所以Adam是一个使用起来最简单的优化方法
optimizer = torch.optim.Adam(model.parameters(), lr=0.001, betas=(0.9, 0.999), eps=1e-08)