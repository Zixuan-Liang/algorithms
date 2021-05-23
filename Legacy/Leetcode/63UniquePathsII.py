# Follow up for "Unique Paths":
#
# Now consider if some obstacles are added to the grids. How many unique paths would there be?
#
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
#
# For example,
# There is one obstacle in the middle of a 3x3 grid as illustrated below.
#
# [
#   [0,0,0],
#   [0,1,0],
#   [0,0,0]
# ]
# The total number of unique paths is 2.

def unique_paths(m, n, grid):
    table = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                table[i][j] = 0
            elif i == 0 and j == 0:
                table[i][j] = 1
            elif i == 0:
                table[i][j] = table[i][j - 1]
            elif j == 0:
                table[i][j] = table[i - 1][j]
            else:
                table[i][j] = table[i][j - 1] + table[i - 1][j]
    return table[m - 1][n - 1]

def unique_paths_with_obstacles(obstacleGrid):
    row_dim = len(obstacleGrid)
    if row_dim == 0:
        return 0
    col_dim = len(obstacleGrid[0])
    return unique_paths(row_dim, col_dim, obstacleGrid)
