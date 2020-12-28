from typing import List

class DisjointSets:
    def __init__(self, N):
        self.N = N
        self.count = self.N
        self.parent = [i for i in range(self.N)]
        self.rank = [0 for i in range(self.N)]
    
    def find(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    
    def union(self, x, y):
        rootx = self.find(x)
        rooty = self.find(y)
        if rootx != rooty:
            if self.rank[rootx] > self.rank[rooty]:
                self.parent[rooty] = rootx
            elif self.rank[rooty] > self.rank[rootx]:
                self.parent[rootx] = rooty
            else:
                self.parent[rooty] = rootx
                self.rank[rootx] += 1
            self.count -= 1

class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        N = len(M)
        ds = DisjointSets(N)
        for r in range(N):
            for c in range(N):
                if M[r][c] == 1:
                    ds.union(r, c)
        return ds.count