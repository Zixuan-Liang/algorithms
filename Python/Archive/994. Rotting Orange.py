import collections

# time O(RC), space O(RC)

class Solution:
    def orangesRotting(self, grid):
        R, C = len(grid), len(grid[0])
        queue = collections.deque()
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 2:
                    queue.append((r, c, 0))
        def neighbors(r, c):
            for nr, nc in ((r-1,c),(r,c-1),(r+1,c),(r,c+1)):
                if 0<=nr<R and 0<=nc<C:
                    yield nr, nc
        d = 0
        while queue:
            r, c, d = queue.popleft()
            for nr, nc in neighbors(r, c):
                if grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    queue.append((nr, nc, d+1))
        if any(1 in row for row in grid):
            return -1
        return d