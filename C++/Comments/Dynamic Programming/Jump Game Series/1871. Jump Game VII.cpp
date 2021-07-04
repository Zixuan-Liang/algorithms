// Explanation
// dp[i] = true if we can reach s[i].
// pre means the number of previous position that we can jump from.


// Complexity
// Time O(n)
// Space O(n)

class Solution {
public:

    bool canReach(string s, int minJ, int maxJ) {
        int n = s.size(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJ)
                pre += dp[i - minJ]; // sliding window in
            if (i > maxJ)
                pre -= dp[i - maxJ - 1]; // sliding window out
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
    
};