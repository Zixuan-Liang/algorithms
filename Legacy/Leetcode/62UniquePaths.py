# A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
#
# The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
#
# How many possible unique paths are there?

def unique_paths(m, n):
    table = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                table[i][j] = 1
            elif i == 0:
                table[i][j] = table[i][j - 1]
            elif j == 0:
                table[i][j] = table[i - 1][j]
            else:
                table[i][j] = table[i][j - 1] + table[i - 1][j]
    return table[m - 1][n - 1]

