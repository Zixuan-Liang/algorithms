# Given a triangle, find the minimum path sum from top to bottom. 
# Each step you may move to adjacent numbers on the row below.

from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        dp = [0 for i in range(n)]
        dp[0] = triangle[0][0]
        for i in range(1, n):
            row = triangle[i]
            row_len = len(row)
            dp[row_len-1] = row[row_len-1] + dp[row_len-2]
            for j in range(row_len-2,0,-1):
                dp[j] = min(dp[j-1]+row[j], dp[j]+row[j])
            dp[0] += row[0]        
        return min(dp)

solution = Solution()
triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
print(solution.minimumTotal(triangle))