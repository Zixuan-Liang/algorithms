class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();
        vector<vector<vector<int>>> memo(m+1, vector<vector<int>>(n+2, vector<int>(4, 0)));
        int h = 0, v = 0, d = 0, ad = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i-1][j-1] == 1) {
                    h = memo[i][j][0] = memo[i][j-1][0] + 1;
                    v = memo[i][j][1] = memo[i-1][j][1] + 1;
                    d = memo[i][j][2] = memo[i-1][j-1][2] + 1;
                }
                if (mat[i-1][n-j] == 1) {
                    ad = memo[i][n+1-j][3] = memo[i-1][n+2-j][3] + 1;
                }
                res = max({res, h, v, d, ad});
            }
        }
        return res;
    }
};