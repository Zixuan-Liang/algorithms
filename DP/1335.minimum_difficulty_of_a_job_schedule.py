class Solution:

    def minDifficulty(self, A, d):
        n = len(A)
        if d > n:
            return -1
        inf = float('inf')
        dp = [[inf for _ in range(d+1)] for _ in range(n+1)]
        dp[0][0] = 0
        for i in range(1, n+1):
            for k in range(1, d+1):
                max_d = 0
                for j in range(i-1, k-2, -1):
                    max_d = max(max_d, A[j])
                    dp[i][k] = min(dp[i][k], dp[j][k-1]+max_d)
                    
        return dp[n][d]