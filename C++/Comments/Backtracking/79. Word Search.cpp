class Solution {
    
    int m;
    int n;
    vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
    function<bool(int, int)> outbound = [&](int i, int j)->bool{return i<0 || i>=m || j<0 || j>=n;};
    
public:
    
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.size()) {
            return true;
        }
        else if (outbound(i, j) || board[i][j] != word[index]) {
            return false;
        }
        else {
            board[i][j] = '#';
            bool res = false;
            for (auto [di, dj] : adjs) {
                int ni = i + di, nj = j + dj;
                res = res || backtrack(board, word, ni, nj, index + 1);
            }
            board[i][j] = word[index];
            return res;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};