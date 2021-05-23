# Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
#
# For example,
# Given n = 3,
#
# You should return the following matrix:
# [
#  [ 1, 2, 3 ],
#  [ 8, 9, 4 ],
#  [ 7, 6, 5 ]
# ]

def spiral_order(n):
    right, down, left, up = 1, 2, 3, 4
    if n == 0:
        return []
    size = n ** 2
    row, col = 0, 0
    visit = [[False for _ in range(n)] for _ in range(n)]
    ans = [[0 for _ in range(n)] for _ in range(n)]
    dir = right
    for i in range(size):
        ans[row][col] = i + 1
        visit[row][col] = True
        if dir == right:
            if row == 0 and col == n - 1 or visit[row][col + 1] == True:
                dir = down
                row += 1
            else:
                col += 1
        elif dir == down:
            if row == n - 1 and col == n - 1 or visit[row + 1][col] == True:
                dir = left
                col -= 1
            else:
                row += 1
        elif dir == left:
            if row == n - 1 and col == 0 or visit[row][col - 1] == True:
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

print spiral_order(3)