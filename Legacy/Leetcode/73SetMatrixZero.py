# Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
#
# Did you use extra space?
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?

import sys

def set_zeroes(matrix):
    m = len(matrix)
    n = len(matrix[0])
    for row in matrix:
        flag = False
        for num in row:
            if num == 0:
                flag = True
                break
        if flag == True:
            for i in range(n):
                if row[i] != 0:
                    row[i] = sys.maxint
                else:
                    for j in range(m):
                        if matrix[j][i] != 0:
                            matrix[j][i] = sys.maxint
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == sys.maxint:
                matrix[i][j] = 0