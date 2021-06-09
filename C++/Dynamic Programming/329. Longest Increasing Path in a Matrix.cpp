class Solution {
    
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int m, n;
    
public:
    
    int search(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != 1) return memo[i][j];
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], 1+search(matrix, x, y, memo));
            }
        }
        return memo[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        m = matrix.size(); n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 1));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, search(matrix, i, j, memo));
            }
        }
        return res;
    }
};