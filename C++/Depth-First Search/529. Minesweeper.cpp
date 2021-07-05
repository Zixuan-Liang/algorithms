class Solution {

    int m;
    int n;
    vector<pair<int, int>> adjs = {{-1,-1},{-1,1},{1,-1},{1,1},{-1,0},{1,0},{0,1},{0,-1}};
    
public:
    
    void helper(vector<vector<char>>& board, int r, int c) {
        int count = 0;
        for (auto [dr, dc] : adjs) {
            int nr = r + dr, nc = c + dc;
            if (nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'M') {
                count++;
            }
        }
        if (count > 0) {
            board[r][c] = '0' + count;
            return ;
        }
        else {
            board[r][c] = 'B';
            for (auto [dr, dc] : adjs) {
                int nr = r + dr, nc = c + dc;
                if (nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'E') {
                    helper(board, nr, nc);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        else {
            helper(board, r, c);
            return board;
        }
    }
};