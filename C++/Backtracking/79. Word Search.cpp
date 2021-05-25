class Solution {
public:
   
    bool backtrack(vector<vector<char>>& board, string& word, int x, int y, int index) {
        if (index == word.size()) return true;
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size() || word[index]!=board[x][y]) return false;
        char temp = board[x][y];
        board[x][y] = '#';
        bool res = backtrack(board, word, x-1, y, index+1) || backtrack(board, word, x+1, y, index+1) || 
            backtrack(board, word, x, y-1, index+1) || backtrack(board, word, x, y+1, index+1);
        board[x][y] = temp;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {        
        int m = board.size(), n = board[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (backtrack(board, word, x, y, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};