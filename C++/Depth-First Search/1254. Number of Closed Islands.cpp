class Solution {
public:
    
    bool search(vector<vector<int>>& grid, int i, int j) {
        bool closed = i > 0 && i < grid.size()-1 && j > 0 && j < grid[0].size()-1;
        grid[i][j] = 1;
        vector<vector<int>> neighbors = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto& n : neighbors) {
            int ni = i + n[0], nj = j + n[1];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 0) {
                bool next = search(grid, ni, nj);
                closed = closed && next;
            }
        }
        return closed;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && search(grid, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
};