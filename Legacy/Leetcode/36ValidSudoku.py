# The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
# A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

def is_valid_sudoko(board):

    used_row = [[0 for _ in range(9)] for _ in range(9)]
    used_col = [[0 for _ in range(9)] for _ in range(9)]
    used_blo = [[0 for _ in range(9)] for _ in range(9)]

    board_len = len(board)
    for i in range(board_len):
        blo_len = len(board[i])
        for j in range(blo_len):
            if board[i][j] != '.':
                num = int(board[i][j]) - 1
                k = i / 3 * 3 + j / 3
                if used_row[i][num] != 0 or used_col[j][num] != 0 or used_blo[k][num] != 0:
                    return False
                used_row[i][num] = used_col[j][num] = used_blo[k][num] = 1
    return  True

board = [".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]
print is_valid_sudoko(board)