from functools import lru_cache

class Solution:
    def palindromePartition(self, s, k):
        n = len(s)
        cost = [[0] * n for _ in range(n)]
        for span in range(2, n + 1):
            for i in range(n - span + 1):
                j = i + span - 1
                cost[i][j] = cost[i + 1][j - 1] + (0 if s[i] == s[j] else 1)

        # f = [[10**9] * (k + 1) for _ in range(n + 1)]
        # f[0][0] = 0
        # for i in range(1, n + 1):
        #     for j in range(1, min(k, i) + 1):
        #         if j == 1:
        #             f[i][j] = cost[0][i - 1]
        #         else:
        #             for i0 in range(j - 1, i):
        #                 f[i][j] = min(f[i][j], f[i0][j - 1] + cost[i0][i - 1])

        # 注释掉的代码是自底向上动态规划
        # 改写成递归式memo with lru_cache:
        @lru_cache(maxsize=None)
        def dp(i, j):
            if i == 0 and j == 0:
                return 0
            if j == 1:
                return cost[0][i-1]
            minVal = float('inf')
            for i0 in range(j - 1, i):
                minVal = min(minVal, dp(i0, j-1) + cost[i0][i-1])
            return minVal

        return dp(n, k)
