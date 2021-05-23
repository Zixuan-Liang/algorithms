# Given a 2D board and a word, find if the word exists in the grid.
#
# The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
#
# For example,
# Given board =
#
# [
#   ['A','B','C','E'],
#   ['S','F','C','S'],
#   ['A','D','E','E']
# ]
# word = "ABCCED", -> returns true,
# word = "SEE", -> returns true,
# word = "ABCB", -> returns false.

def find_word(board, i, j, word):
    if len(word) == 0: # all the characters are checked
        return True
    if i<0 or i>=len(board) or j<0 or j>=len(board[0]) or word[0]!=board[i][j]:
        return False
    tmp = board[i][j]  # first character is found, check the remaining part
    board[i][j] = '#'  # avoid visit agian
    # check whether can find "word" along one direction
    res = find_word(board, i+1, j, word[1:]) or find_word(board, i-1, j, word[1:]) \
    or find_word(board, i, j+1, word[1:]) or find_word(board, i, j-1, word[1:])
    board[i][j] = tmp
    return res


def exist(board, word):
    if not board :
        return False
    for i in range(len(board)):
        for j in range(len(board[0])):
            if find_word(board, i, j, word):
                return True
    return False

board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
word1 = "ABCCED"
word2 = "SEE"
word3 = "ABCB"
board2 = ["ABCE","SFES","ADEE"]
board2 = [[ele for ele in row] for row in board2]
word4 = 'ABCESEEEFS'

print exist(board, word1)
print exist(board, word2)
print exist(board, word3)
print exist(board2, word4)