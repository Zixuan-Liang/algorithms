# bottom-up
def knapsack(W, wt, val, n):
    dp = [[0 for _ in range(W+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(W+1):
            if wt[i-1] <= j:
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][W]

val = [60, 100, 120] 
wt = [10, 20, 30] 
W = 50
n = len(val) 
print(knapsack(W, wt, val, n)) 

# top-down
dp = [[-1 for _ in range(W+1)] for _ in range(n+1)]
def knapsack2(W, wt, val, n):
    if n==0 or W==0:
        return 0
    if dp[n][W] != -1:
        return dp[n][W]
    if wt[n-1] <= W:
        dp[n][W] = max(val[n-1]+knapsack2(W-wt[n-1], wt, val, n-1), 
                        knapsack2(W, wt, val, n-1))
        return dp[n][W]
    elif wt[n-1] > W:
        dp[n][W] = knapsack2(W, wt, val, n-1)
        return dp[n][W]

print(knapsack2(W, wt, val, n))

# bottom-up save memory
def knapsack3(val, wt, n, W): 
    dp = [0 for _ in range(W+1)] 
    for i in range(n):
        for w in range(W, -1, -1):
            if wt[i] <= w:
                dp[w] = max(dp[w], val[i]+dp[w-wt[i]])
    return dp[W]

print(knapsack3(val, wt, n, W))
