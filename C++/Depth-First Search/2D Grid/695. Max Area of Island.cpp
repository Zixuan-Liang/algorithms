class Solution {
    
    int m;
    int n;
    vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
    
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        int area = 1;
        for (auto [di, dj] : adjs) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 and ni < m and nj >= 0 and nj < n and grid[ni][nj] == 1) {
                area += dfs(grid, ni, nj);
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};