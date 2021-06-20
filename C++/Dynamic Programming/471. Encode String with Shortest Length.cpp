class Solution {
public:
    string encode(string s) {
        
        int n = s.size();
        
        if (n < 5) return s;
        
        vector<vector<string>> dp(n, vector<string>(n, ""));
        
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start + len <= n; start++) {
                int end = start + len - 1;
                string shortest = s.substr(start, len);
                if (len < 5) {
                    dp[start][end] = shortest;
                    continue;
                }
                
                int repeatPos = (shortest + shortest).find(shortest, 1);
                if (repeatPos < shortest.size()) {
                    shortest = to_string(shortest.size() / repeatPos) + "[" + dp[start][start + repeatPos - 1] + "]";
                }
                for (int p = start; p < end; p++) {
                    if (dp[start][p].size() + dp[p+1][end].size() < shortest.size()) {
                        shortest = dp[start][p] + dp[p+1][end];
                    }
                }
                dp[start][end] = shortest;
            }
        }
        return dp[0][n-1];
        
    }
};