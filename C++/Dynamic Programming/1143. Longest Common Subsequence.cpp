class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if (m < n) return longestCommonSubsequence(text2, text1);
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        int dp_row = 0;
        for (int i = 1; i <= m; i++) {
            dp_row = 1 - dp_row;
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[dp_row][j] = 1 + dp[1 - dp_row][j-1];
                }
                else {
                    dp[dp_row][j] = max(dp[1 - dp_row][j], dp[dp_row][j-1]);
                }
            }
        }
        return dp[dp_row][n];
    }
};