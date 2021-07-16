class Solution {
    
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> adjs={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<vector<int>> q;
        if (grid[0][0] == 1) return -1;
        unordered_set<int> visited;
        q.push({0, 0});
        visited.insert(0);
        int res = 1;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto cell = q.front(); q.pop();
                if (cell[0] == m-1 && cell[1] == n-1) return res;
                for (auto [dr, dc] : adjs) {
                    int r = cell[0] + dr, c = cell[1] + dc;
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 0 && visited.find((r<<10)+c) == visited.end()) {
                        q.push({r, c});
                        visited.insert((r<<10)+c);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};