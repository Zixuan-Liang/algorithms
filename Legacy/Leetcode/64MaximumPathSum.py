# Given a m x n grid filled with non-negative numbers,
# find a path from top left to bottom right which minimizes the sum of all numbers along its path.
#
# Note: You can only move either down or right at any point in time.

def path_sum(m, n, grid):
    table = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                table[i][j] = grid[i][j]
            elif i == 0:
                table[i][j] = table[i][j - 1] + grid[i][j]
            elif j == 0:
                table[i][j] = table[i - 1][j] + grid[i][j]
            else:
                table[i][j] = min(table[i][j - 1], table[i - 1][j]) + grid[i][j]
    return table[m - 1][n - 1]

def min_path_sum(grid):
    row_dim = len(grid)
    if row_dim == 0:
        return 0
    col_dim = len(grid[0])
    return path_sum(row_dim, col_dim, grid)