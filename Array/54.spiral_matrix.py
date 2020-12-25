from typing import List

class Solution:
    def solve(self, i, j):
        ans = []
        if i >= self.m or j >= self.n or self.visited[i][j] == 1:
            return ans
        elif i+1 >= self.m or self.visited[i+1][j] == 1:
            while j < self.n and self.visited[i][j] == 0:
                ans.append(self.matrix[i][j])
                self.visited[i][j] = 1
                j += 1
        else:
            while j < self.n and self.visited[i][j] == 0:
                ans.append(self.matrix[i][j])
                self.visited[i][j] = 1
                j += 1
            j -= 1
            i += 1
            while i < self.m and self.visited[i][j] == 0:
                ans.append(self.matrix[i][j])
                self.visited[i][j] = 1
                i += 1
            i -= 1
            j -= 1
            while j >= 0 and self.visited[i][j] == 0:
                ans.append(self.matrix[i][j])
                self.visited[i][j] = 1
                j -= 1
            j += 1
            i -= 1
            while i >= 0 and self.visited[i][j] == 0:
                ans.append(self.matrix[i][j])
                self.visited[i][j] = 1
                i -= 1
            ans += self.solve(i+1, j+1)
        return ans
    
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        self.matrix = matrix
        self.m = len(matrix)
        self.n = len(matrix[0])
        self.visited = [[0 for i in range(self.n)] for i in range(self.m)]
        return self.solve(0, 0)