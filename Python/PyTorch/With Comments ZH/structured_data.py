
import numpy as np
import pandas as pd
import torch
from sklearn.preprocessing import LabelEncoder
from torch.utils.data import Dataset, DataLoader
import torch.nn.functional as F
import torch.nn as nn
from collections import Counter

# 结构化数据可以理解为就是一张2维的表格，例如一个csv文件，就是结构化数据，在英文一般被称作Tabular Data或者叫 structured data

# 我们拿到的结构化数据，一般都是一个csv文件或者数据库中的一张表格，所以对于结构化的数据，我们直接使用pasdas库处理就可以了

#读入文件
df = pd.read_csv('./data/adult.csv')
#salary是这个数据集最后要分类的结果
df['salary'].unique()

#训练结果
result_var = 'salary'
#分类型数据
cat_names = ['workclass', 'education', 'marital-status', 'occupation', 'relationship', 'race','sex','native-country']
#数值型数据
cont_names = ['age', 'fnlwgt', 'education-num','capital-gain','capital-loss','hours-per-week']

# 人工确认完数据类型后，我们可以看一下分类类型数据的数量和分布情况

for col in df.columns:
    if col in cat_names:
        ccol=Counter(df[col])
        print(col,len(ccol),ccol)
        print("\r\n")

# 下一步就是要将分类型数据转成数字型数据，在这部分里面，我们还做了对于缺失数据的填充

for col in df.columns:
    if col in cat_names:
        df[col].fillna('---')
        df[col] = LabelEncoder().fit_transform(df[col].astype(str))
    if col in cont_names:
        df[col]=df[col].fillna(0)

# 数据处理完成后可以看到，现在所有的数据都是数字类型的了，可以直接输入到模型进行训练了.

Y = df['salary']
Y_label = LabelEncoder()
Y=Y_label.fit_transform(Y)

X=df.drop(columns=result_var)

# 以上，基本的数据预处理已经完成了，上面展示的只是一些必要的处理，如果要提高训练准确率还有很多技巧

# 要使用pytorch处理数据，肯定要使用Dataset进行数据集的定义，下面定义一个简单的数据集

class tabularDataset(Dataset):
    def __init__(self, X, Y):
        self.x = X.values
        self.y = Y
        
    def __len__(self):
        return len(self.y)
    
    def __getitem__(self, idx):
        return (self.x[idx], self.y[idx])

train_ds = tabularDataset(X, Y)

# 可以直接使用索引访问定义好的数据集中的数据

print(train_ds[0])

# 数据已经准备完毕了，下一步就是要定义我们的模型了，这里使用了3层线性层的简单模型作为处理

class tabularModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.lin1 = nn.Linear(14, 500)
        self.lin2 = nn.Linear(500, 100)
        self.lin3 = nn.Linear(100, 2)
        self.bn_in = nn.BatchNorm1d(14)
        self.bn1 = nn.BatchNorm1d(500)
        self.bn2 = nn.BatchNorm1d(100)
        

    def forward(self,x_in):
        #print(x_in.shape)
        x = self.bn_in(x_in)
        x = F.relu(self.lin1(x))
        x = self.bn1(x)
        #print(x)
        
        
        x = F.relu(self.lin2(x))
        x = self.bn2(x)
        #print(x)
        
        x = self.lin3(x)
        x=torch.sigmoid(x)
        return x

# 在定义模型的时候看到了我们加入了Batch Normalization来做批量的归一化

#训练前指定使用的设备
DEVICE=torch.device("cpu")
if torch.cuda.is_available():
        DEVICE=torch.device("cuda")
print(DEVICE)

#损失函数
criterion = nn.CrossEntropyLoss()

#实例化模型
model = tabularModel().to(DEVICE)
print(model)

#测试模型是否没问题
rn=torch.rand(3,14).to(DEVICE)
model(rn)

#学习率
LEARNING_RATE=0.01
#BS
batch_size = 1024
#优化器
optimizer = torch.optim.Adam(model.parameters(), lr=LEARNING_RATE)

#DataLoader加载数据
train_dl = DataLoader(train_ds, batch_size=batch_size,shuffle=True)

# 以上的基本步骤是每个训练过程都需要的，所以就不多介绍了，下面开始进行模型的训练

model.train()
#训练10轮
TOTAL_EPOCHS=100
#记录损失函数
losses = []
for epoch in range(TOTAL_EPOCHS):
    for i, (x, y) in enumerate(train_dl):
        x = x.float().to(DEVICE) #输入必须未float类型
        y = y.long().to(DEVICE) #结果标签必须未long类型
        #清零
        optimizer.zero_grad()
        outputs = model(x)
        #计算损失函数
        loss = criterion(outputs, y)
        loss.backward()
        optimizer.step()
        losses.append(loss.cpu().data.item())
    print ('Epoch : %d/%d,   Loss: %.4f'%(epoch+1, TOTAL_EPOCHS, np.mean(losses)))

# 训练完成后我们可以看一下模型的准确率

model.eval()
correct = 0
total = 0
for i,(x, y) in enumerate(train_dl):
    x = x.float().to(DEVICE)
    y = y.long()
    outputs = model(x).cpu()
    _, predicted = torch.max(outputs.data, 1)
    total += y.size(0)
    correct += (predicted == y).sum()
print('准确率: %.4f %%' % (100 * correct / total))

# 以上就是基本的流程了