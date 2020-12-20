from typing import List

# # DFS
# class Solution:
#     def dfs(self, grid, r, c):
#         nr = len(grid)
#         nc = len(grid[0])
#         grid[r][c] = '0'
#         if r-1>=0 and grid[r-1][c]=='1':
#             self.dfs(grid, r-1, c)
#         if r+1<nr and grid[r+1][c]=='1':
#             self.dfs(grid, r+1, c)
#         if c-1>=0 and grid[r][c-1]=='1':
#             self.dfs(grid, r, c-1)
#         if c+1<nc and grid[r][c+1]=='1':
#             self.dfs(grid, r, c+1)
    
#     def numIslands(self, grid: List[List[str]]) -> int:
#         nr = len(grid)
#         if nr == 0:
#             return 0
#         nc = len(grid[0])
        
#         ans = 0
#         for i in range(nr):
#             for j in range(nc):
#                 if grid[i][j] == '1':
#                     ans += 1
#                     self.dfs(grid, i, j)
#         return ans

# BFS
from collections import deque as Queue
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        nr = len(grid)
        if nr == 0:
            return 0
        nc = len(grid[0])
        ans = 0
        for r in range(nr):
            for c in range(nc):
                if grid[r][c] == '1':
                    ans += 1
                    grid[r][c] = '0'
                    neighbors = Queue()
                    neighbors.append([r, c])
                    while len(neighbors) != 0:
                        rc = neighbors[0]
                        neighbors.popleft()
                        row = rc[0]
                        col = rc[1]
                        if row-1>=0 and grid[row-1][col] == '1':
                            neighbors.append([row-1, col])
                            grid[row-1][col] = '0'
                        if row+1<nr and grid[row+1][col] == '1':
                            neighbors.append([row+1, col])
                            grid[row+1][col] = '0'
                        if col-1>=0 and grid[row][col-1] == '1':
                            neighbors.append([row, col-1])
                            grid[row][col-1] = '0'
                        if col+1<nc and grid[row][col+1] == '1':
                            neighbors.append([row, col+1])
                            grid[row][col+1] = '0'
        return ans