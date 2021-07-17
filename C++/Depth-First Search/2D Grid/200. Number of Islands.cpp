class Solution {
public:
    
    int m, n;
    vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (auto [di, dj] : adjs) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                dfs(grid, ni, nj);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};