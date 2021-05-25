class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m == 0 || n == 0) return m+n;
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i++) {
            memo[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            memo[0][j] = j;
        }
        int d1, d2, d3;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                d1 = memo[i-1][j] + 1;
                d2 = memo[i][j-1] + 1;
                d3 = memo[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                memo[i][j] = min({d1, d2, d3});
            }
        }
        return memo[m][n];
    }
    
};