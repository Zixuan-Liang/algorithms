class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        if (m == n) return s==t;
        vector<vector<long>> memo(m+1, vector<long>(n+1, 0));
        for (int i = 0; i < m+1; i++) memo[i][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                memo[i][j] = memo[i-1][j] + memo[i-1][j-1] * (s[i-1]==t[j-1]);
            }
        }
        return memo[m][n];
    }
};