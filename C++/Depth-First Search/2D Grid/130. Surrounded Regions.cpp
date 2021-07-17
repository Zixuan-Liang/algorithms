class Solution {
    
    int m;
    int n;
    vector<vector<int>> visited;
    vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
    
public:
    
    bool isEdge(int i, int j) {
        return i==0 or i==m-1 or j==0 or j==n-1;
    }
    
    bool isLegit(int i, int j) {
        return i >= 0 and i < m and j >= 0 and j < n;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, bool flip) {
        board[i][j] = flip ? 'X' : board[i][j];
        visited[i][j] = 1;
        for (auto [di, dj] : adjs) {
            int ni = i + di, nj = j + dj;
            if (isLegit(ni, nj) and board[ni][nj] == 'O' and visited[ni][nj] == 0) {
                dfs(board, ni, nj, flip);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<int>>(m, vector<int>(n, 0));        
        // Exclude the regions that are NOT surrounded
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isEdge(i, j) and board[i][j] == 'O' and visited[i][j] == 0) {
                    dfs(board, i, j, false);
                }
            }
        }
        // Flip surrounded regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' and visited[i][j] == 0) {
                    dfs(board, i, j, true);
                }
            }
        }
    }
};