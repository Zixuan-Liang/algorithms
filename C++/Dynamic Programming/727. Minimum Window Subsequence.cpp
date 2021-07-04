// dp[i][j] stores the starting index of the substring where T has length i and S has length j.

// So dp[i][j] would be:
// if T[i - 1] == S[j - 1], this means we could borrow the start index from dp[i - 1][j - 1] to make the current substring valid;
// else, we only need to borrow the start index from dp[i][j - 1] which could either exist or not.

// Finally, go through the last row to find the substring with min length and appears first.


class Solution {
public:
    string minWindow(string source, string target) {
        int m = target.size(), n = source.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j + 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (target[i - 1] == source[j - 1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        // Finally, go through the last row to find the substring with min length and appears first.
        int start = 0, len = n + 1;
        for (int j = 1; j <= n; j++) {
            if (dp[m][j] != 0) {
                if (j - dp[m][j] + 1 < len) {
                    start = dp[m][j] - 1;
                    len = j - dp[m][j] + 1;
                }
            }
        }
        return len == n + 1 ? "" : source.substr(start, len);
    }
};