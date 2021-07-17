class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    queue<vector<int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        vector<int> position = q.front();
                        q.pop();
                        int x = position[0], y = position[1];
                        for (auto [dx, dy] : adjs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                q.push({nx, ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};