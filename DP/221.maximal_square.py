class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        nr = len(matrix)
        if nr == 0:
            return 0
        nc = len(matrix[0])
        dp = [[0 for i in range(nc+1)] for i in range(nr+1)]
        ans = 0
        for i in range(nr):
            for j in range(nc):
                if matrix[i][j] == "1":
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]) + 1
                    ans = max(ans, dp[i+1][j+1])
        return ans * ans