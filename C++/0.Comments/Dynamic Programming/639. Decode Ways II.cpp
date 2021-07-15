class Solution {
public:
    
    int MOD = 1e9+7;
    
    int numDecodings(string s) {
        vector<long> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '*') {
                dp[i + 1] = 9 * dp[i] % MOD;
                if (s[i - 1] == '1') {
                    dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '2') {
                    dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '*') {
                    dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % MOD;
                }
            }
            else {
                dp[i + 1] = s[i] != '0' ? dp[i] : 0;
                if (s[i - 1] == '1') {
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '2' && s[i] <= '6') {
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
                }
                else if (s[i - 1] == '*') {
                    dp[i + 1] = dp[i + 1] + (s[i] <= '6' ? 2 : 1) * dp[i - 1] % MOD;
                }
            }
        }
        return dp[s.size()];
    }
};