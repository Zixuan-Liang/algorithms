class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> adjs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int m = board.size(), n = board[0].size();
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++) {
                int lives = 0;
                for (auto [dx, dy] : adjs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && abs(board[nx][ny]) == 1) {
                        lives++;
                    }
                }
                if (board[x][y] == 1 && (lives < 2 || lives > 3))
                    board[x][y] = -1;
                if (board[x][y] == 0 && lives == 3)
                    board[x][y] = 2;
            }
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++) {
                if (board[x][y] > 0)
                    board[x][y] = 1;
                else
                    board[x][y] = 0;
            }
    }
};