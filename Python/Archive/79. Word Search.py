class Solution:
                    
    def exist(self, board, word):
        M, N, L = len(board), len(board[0]), len(word)
        
        def find_word(x, y, i):
            if i == L:
                return True
            if x<0 or x>=M or y<0 or y>=N or word[i]!=board[x][y]:
                return False
            temp = board[x][y] 
            board[x][y] = "visited" 
            ans = find_word(x+1, y, i+1) or find_word(x, y+1, i+1) or find_word(x-1, y, i+1) or find_word(x, y-1, i+1)
            board[x][y] = temp
            return ans
        
        for x in range(M):
            for y in range(N):
                if find_word(x, y, 0):
                    return True
                
        return False
                    