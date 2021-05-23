# Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
#
# Integers in each row are sorted from left to right.
# The first integer of each row is greater than the last integer of the previous row.
# For example,
#
# Consider the following matrix:
#
# [
#   [1,   3,  5,  7],
#   [10, 11, 16, 20],
#   [23, 30, 34, 50]
# ]
# Given target = 3, return true.

def search_matrix(matrix, target):
    flatten = [num for row in matrix for num in row]
    length = len(flatten)
    if length == 0:
        return False
    start = 0
    end = length - 1
    while start != end:
        mid = start + (end - start)/2
        if target == flatten[mid]:
            return True
        elif target < flatten[mid]:
            end = mid
        else:
            start = mid + 1
    if flatten[start] == target:
        return True
    else:
        return False
