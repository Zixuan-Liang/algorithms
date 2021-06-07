class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == 1) {
                    memo[i][j] = min({memo[i-1][j-1], memo[i-1][j], memo[i][j-1]}) + 1;
                    res += memo[i][j];
                }
            }
        }
        return res;
    }
};