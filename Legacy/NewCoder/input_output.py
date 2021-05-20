# a+b, 输入多行，每行都是数据
lines = []
while True:
    try:
        line = list(map(int, input().split()))
        lines.append(line)
    except:
        break
for line in lines:
    print(line[0] + line[1])

# a+b，输入多行，第一行是组数
lines = []
n = int(input())
for _ in range(n):
    try:
        line = list(map(int, input().split()))
        lines.append(line)
    except:
        break
for line in lines:
    print(line[0] + line[1])

# 排序输入字符串，输入多行，每行都是数据
lines = []
while True:
    try:
        line = list(map(str, input().split()))
        lines.append(line)
    except:
        break
for line in lines:
    line.sort()
    length = len(line)
    for i in range(length-1):
        print(line[i], end=" ")
    print(line[-1])
    # ans = " ".join(line)
    # print(ans)