class Solution {

public:
    
    vector<vector<int>> neighbors(int r, int c, int m, int n) {
        vector<vector<int>> points = {{r-1,c-1},{r-1,c},{r-1,c+1},{r,c-1},{r,c+1},{r+1,c-1},{r+1,c},{r+1,c+1}};
        vector<vector<int>> res;
        for (auto& p : points) {
            if (p[0] >= 0 && p[0] < m && p[1] >= 0 && p[1] < n) {
                res.push_back(p);
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& board, int r, int c, int m, int n) {
        vector<vector<int>> points = neighbors(r, c, m, n);
        int count = 0;
        for (auto& p : points) {
            if (board[p[0]][p[1]] == 'M') {
                count++;
            }
        }
        if (count > 0) {
            board[r][c] = '0' + count;
            return ;
        }
        else {
            board[r][c] = 'B';
            for (auto& p : points) {
                if (board[p[0]][p[1]] == 'E') {
                    helper(board, p[0], p[1], m, n);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        else {
            helper(board, r, c, m, n);
            return board;
        }
    }
};