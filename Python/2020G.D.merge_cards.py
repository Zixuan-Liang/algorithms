maxn = 5001
dp = [[0 for _ in range(maxn - i)] for i in range(maxn)]

for i in range(maxn):
    for j in range(maxn - i):
        if i or j:
            tot = 0
            prob = 1.0 / (i+j)
            if i > 0:
                tot += prob * (1 + dp[i-1][j])
            if j > 0:
                tot += prob * (1 + dp[i][j-1])
            if i > 1:
                tot += (i-1)/(i+j) * dp[i-1][j]
            if j > 1:
                tot += (j-1)/(i+j) * dp[i][j-1]
            dp[i][j] = tot
T = int(input())
for cas in range(T):
    n = int(input())
    num = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        ans += dp[i][n-1-i] * num[i]
    print ("Case #{}: {:.10f}".format(cas + 1, ans))
