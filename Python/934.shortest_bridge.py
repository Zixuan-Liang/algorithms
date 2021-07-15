from collections import deque as Queue

class Solution:

    def shortestBridge(self, A: List[List[int]]) -> int:
        
        rows, cols = len(A), len(A[0])
    
        def neighbors(r, c):
            for nr, nc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
                if 0<=nr<rows and 0<=nc<cols:
                    yield nr, nc

        water = Queue()
        seen = set()

        def dfs(r, c):
            A[r][c] = 2
            for nr, nc in neighbors(r, c):
                if A[nr][nc] == 1:
                    dfs(nr, nc)
                else:
                    if (nr, nc) not in seen:
                        water.append((nr, nc))
                        seen.add((nr, nc))
        
        def findFirstIsland():
            for i in range(rows):
                for j in range(cols):
                    if A[i][j] == 1:
                        return i, j
            return -1, -1

        r, c = findFirstIsland()

        if r == -1:
            print('no island at all')
            return -1
        
        dfs(r, c)
        
        res = 1
        while water:
            for _ in range(len(water)):
                r, c = water.popleft()
                for nr, nc in neighbors(r, c):
                    if A[nr][nc] == 1:
                        return res
                    elif A[nr][nc] == 2:
                        continue
                    else:
                        if (nr, nc) not in seen:
                            water.append((nr, nc))
                            seen.add((nr, nc))
            res += 1
        return res