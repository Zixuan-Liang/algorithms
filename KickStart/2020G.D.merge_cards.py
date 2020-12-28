maxn = 5000
p = [[0 for j in range(i)] for i in range(maxn + 1)]
p[1][0] = 0

for i in range(2, maxn + 1):
    for j in range(1, i):
        p[i][j] += p[i - 1][j - 1] * j / (i - 1)
    for j in range(i - 1):
        p[i][j] += p[i - 1][j] * (i - 1 - j) / (i - 1)
    for j in range(i):
        p[i][j] += 1 / (i - 1)
    for j in range(1, i - 1):
        p[i][j] += 1 / (i - 1)

T = int(input())
for cas in range(T):
    n = int(input())
    num = map(int, input().split(' '))
    ans = sum(num * prob for num, prob in zip(num, p[n]))
    print ("Case #{}: {:.10f}".format(cas + 1, ans))
