class Solution {
public:
    int countVowelPermutation(int n) {
        int M = 1e9+7;
        vector<vector<int>> dp(5, vector<int>(n + 1, 0));
        for (int i = 0; i < 5; i++) {
            dp[i][1] = 1;
        }
        for (int j = 2; j <= n; j++) {
            dp[0][j] = dp[1][j-1];
            dp[1][j] = (dp[0][j-1] + dp[2][j-1]) % M;
            dp[2][j] = ((dp[0][j-1] + dp[1][j-1]) % M + (dp[3][j-1] + dp[4][j-1]) % M) % M;
            dp[3][j] = (dp[2][j-1] + dp[4][j-1]) % M;
            dp[4][j] = dp[0][j-1];
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += dp[i][n];
            ans %= M;
        }
        return ans;
    }
};