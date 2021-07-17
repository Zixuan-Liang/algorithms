class Solution {
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        
        queue<vector<int>> q;
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                if (mat[x][y] == 0) {
                    res[x][y] = 0;
                    q.push({x, y});
                }
        
        while (!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            int x = pos[0], y = pos[1];
            for (auto [dx, dy] : adjs) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && res[newX][newY] == INT_MAX) {
                    res[newX][newY] = res[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
        return res;
        
    }
};