class Solution {
    
    int m;
    int n;
    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    
public:
    
    void dfs(vector<vector<int>>& grid, int row, int col, queue<vector<int>>& island1) {
        island1.push({row, col});
        grid[row][col] = 2;
        for (auto [dr, dc] : dirs) {
            int nr = row + dr, nc = col + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                dfs(grid, nr, nc, island1);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        queue<vector<int>> island1;
        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (flag) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, island1);
                    flag = true;
                    break;
                }
            }
        }
        int res = 0;
        while (!island1.empty()) {
            int len = island1.size();
            for (int i = 0; i < len; i++) {
                vector<int> front = island1.front();
                island1.pop();
                int row = front[0], col = front[1];
                for (auto [dr, dc] : dirs) {
                    int nr = row + dr, nc = col + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 2) {
                        if (grid[nr][nc] == 1) return res;
                        island1.push({nr, nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};