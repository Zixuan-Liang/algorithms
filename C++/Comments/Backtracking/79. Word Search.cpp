class Solution {
    
    int m;
    int n;
    vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
    
public:
    
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int matched) {
        if (matched == word.size()) {
            return true;
        }
        else {
            for (auto [di, dj] : adjs) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == word[matched]) {
                    board[ni][nj] = '#';
                    bool res = backtrack(board, word, ni, nj, matched+1);
                    board[ni][nj] = word[matched];
                    if (res) return true;
                }
            }
            return false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    bool res = backtrack(board, word, i, j, 1);
                    board[i][j] = word[0];
                    if (res) return true;
                }
            }
        }
        return false;
    }
};