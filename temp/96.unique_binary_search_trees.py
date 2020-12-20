# How many structurally unique binary search trees given number of nodes n?

class Solution:
    def numTrees(self, n: int) -> int:
        dp = [1]
        for i in range(1, n+1):
            unique = 0
            for j in range(i):
                unique += dp[j]*dp[i-1-j]
            dp.append(unique)
        return dp[-1]