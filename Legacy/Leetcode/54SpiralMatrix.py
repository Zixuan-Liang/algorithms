# Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
#
# For example,
# Given the following matrix:
#
# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
# You should return [1,2,3,6,9,8,7,4,5].

def spiral_order(matrix):
    right, down, left, up = 1, 2, 3, 4
    dim_row = len(matrix)
    if dim_row == 0:
        return []
    dim_col = len(matrix[0])
    size = dim_row * dim_col
    row, col = 0, 0
    visit = [[False for _ in range(dim_col)] for _ in range(dim_row)]
    ans = []
    dir = right
    for i in range(size):
        ans.append(matrix[row][col])
        visit[row][col] = True
        if dir == right:
            if row == 0 and col == dim_col - 1 or visit[row][col + 1] == True:
                dir = down
                row += 1
            else:
                col += 1
        elif dir == down:
            if row == dim_row - 1 and col == dim_col - 1 or visit[row + 1][col] == True:
                dir = left
                col -= 1
            else:
                row += 1
        elif dir == left:
            if row == dim_row - 1 and col == 0 or visit[row][col - 1] == True:
                dir = up
                row -= 1
            else:
                col -= 1
        else:
            if row == 0 and col == 0 or visit[row - 1][col] == True:
                dir = right
                col += 1
            else:
                row -= 1
    return ans

matrix = [[1,2,3],[4,5,6],[7,8,9]]
print spiral_order(matrix)
