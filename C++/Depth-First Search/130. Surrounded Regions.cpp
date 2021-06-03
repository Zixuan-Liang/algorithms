class Solution {
public:
    
    vector<vector<int>> neighbors(vector<int> p, int m, int n) {
        int i = p[0], j = p[1];
        vector<vector<int>> candidates = {{i-1,j},{i+1,j},{i,j-1},{i,j+1}};
        vector<vector<int>> res;
        for (auto& c : candidates) {
            if (c[0]>=0 && c[0]<m && c[1]>=0 && c[1]<n) {
                res.push_back(c);
            }
        }
        return res;
    }
    
    bool isEdge(int i, int j, int m, int n) {
        return i==0 || i==m-1 || j==0 || j==n-1;
    }
    
    void dfs(int i, int j, vector<vector<char>>& board, int m, int n, vector<vector<int>>& visited, vector<vector<int>>& positions, bool& flip) {
        visited[i][j] = 1;
        vector<int> p = {i, j};
        positions.push_back(p);
        for (auto& next : neighbors(p, m, n)) {
            int r = next[0], c = next[1];
            if (board[r][c] == 'O' && visited[r][c] == 0) {
                if (isEdge(r, c, m, n)) flip = false;
                dfs(r, c, board, m, n, visited, positions, flip);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    vector<vector<int>> positions;
                    bool flip = isEdge(i, j, m, n) ? false : true;
                    dfs(i, j, board, m, n, visited, positions, flip);
                    if (flip) {
                        for (auto& p : positions) {
                            board[p[0]][p[1]] = 'X';
                        }
                    }
                }
            }
        }
    }
};