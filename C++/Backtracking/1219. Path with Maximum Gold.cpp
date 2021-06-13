class Solution {
    
    int m;
    int n;
    vector<pair<int, int>> adjs = {{1,0},{-1,0},{0,1},{0,-1}};
    
public:
    
    void backtrack(vector<vector<int>>& grid, int r, int c, int gold, int& res) {
        int temp = grid[r][c];
        gold += temp;
        res = max(res, gold);
        grid[r][c] = 0;
        for (auto [dr, dc] : adjs) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 0) {
                backtrack(grid, nr, nc, gold, res);
            }
        }
        grid[r][c] = temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 ) {
                    backtrack(grid, i, j, 0, res);
                }
            }
        }
        return res;
    }
};