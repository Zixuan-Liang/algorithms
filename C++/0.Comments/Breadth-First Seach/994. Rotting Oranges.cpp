class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<vector<int>> rotten;
        unordered_set<int> visited;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    fresh++;
                if (grid[r][c] == 2) {
                    rotten.push({r, c});
                    visited.insert(r * 100 + c);
                }
            }
        
        if (fresh == 0) return 0;
        
        vector<pair<int, int>> adjs = {{1,0},{-1,0},{0,1},{0,-1}};
        int minutes = 1;
        while (!rotten.empty()) {
            int len = rotten.size();
            for (int i = 0; i < len; i++) {
                vector<int> curr = rotten.front();
                rotten.pop();
                int r = curr[0], c = curr[1];
                for (auto [dr, dc] : adjs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !visited.count(nr*100+nc)) {
                        rotten.push({nr, nc});
                        visited.insert(nr*100+nc);
                        fresh--;
                        if (fresh <= 0) return minutes;
                    }
                }
            }
            minutes++;
        }
        return -1;
    }
};