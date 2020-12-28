from typing import List
from collections import deque as Queue

# DFS with separate function
# class Solution:
#     def dfs(self, i):
#         for j in range(self.N):
#             if self.M[i][j] == 1 and self.visited[j] == 0:
#                 self.visited[j] = 1
#                 self.dfs(j)
#     def findCircleNum(self, M: List[List[int]]) -> int:
#         self.M = M
#         self.N = len(M)
#         self.visited = [0 for _ in range(self.N)]
#         count = 0
#         for i in range(self.N):
#             if self.visited[i] == 0:
#                 self.dfs(i)
#                 count += 1
#         return count

# DFS with nested functions
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        N = len(M)
        visited = [0 for _ in range(N)]
        def dfs(i):
            for j in range(N):
                if M[i][j] == 1 and visited[j] == 0:
                    visited[j] = 1
                    dfs(j)
        count = 0
        for i in range(N):
            if visited[i] == 0:
                dfs(i)
                count += 1
        return count

# BFS with queue
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        N = len(M)
        visited = [0 for _ in range(N)]
        count = 0
        queue = Queue()
        for i in range(N):
            if visited[i] == 0:
                queue.append(i)
                while len(queue) != 0:
                    s = queue.popleft()
                    visited[s] = 1
                    for j in range(N):
                        if M[s][j] == 1 and visited[j] == 0:
                            queue.append(j)
                count += 1
        return count