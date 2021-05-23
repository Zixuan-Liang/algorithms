# You are given an n x n 2D matrix representing an image.
#
# Rotate the image by 90 degrees (clockwise).
#
# Follow up:
# Could you do this in-place?

def rotate(matrix):
    length = len(matrix)
    divide = length / 2
    if length % 2 == 0:
        for i in range(divide):
            for j in range(divide):
                matrix[j][length - 1 - i], matrix[length - 1 - i][length - 1 - j], matrix[length - 1 - j][i], matrix[i][j] = \
                matrix[i][j], matrix[j][length - 1 - i], matrix[length - 1 - i][length - 1 - j], matrix[length - 1 - j][i]
    else:
        for i in range(divide):
            for j in range(divide + 1):
                matrix[j][length - 1 - i], matrix[length - 1 - i][length - 1 - j], matrix[length - 1 - j][i], matrix[i][j] = \
                matrix[i][j], matrix[j][length - 1 - i], matrix[length - 1 - i][length - 1 - j], \
                matrix[length - 1 - j][i]

matrix = [[1,2,3],[4,5,6],[7,8,9]]
rotate(matrix)
print matrix