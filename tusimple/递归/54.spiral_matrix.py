class Solution:
    def spiralOrder(self, matrix):
        res = []
        m, n = len(matrix), len(matrix[0])
        size = m * n
        visited = [[0 for _ in range(n)] for _ in range(m)]

        turn = {'right':'down', 'down':'left', 'left':'up', 'up':'right'}
        transfer = {'right': (0, 1), 'down': (1, 0), 'left': (0, -1), 'up': (-1, 0)}

        def helper(r, c, direction):
            res.append(matrix[r][c])
            visited[r][c] = 1
            if len(res) == size:
                return
            nr, nc = r+transfer[direction][0], c+transfer[direction][1]
            if 0<=nr<m and 0<=nc<n and not visited[nr][nc]:
                helper(nr, nc, direction)
            else:
                newDirection = turn[direction]
                nr, nc = r+transfer[newDirection][0], c+transfer[newDirection][1]
                helper(nr, nc, newDirection)

        helper(0, 0, 'right')
        return res