#include <algorithm>

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> memo(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    memo[i] = (i>=2 ? memo[i-2] : 0) + 2;
                }
                else if (i - memo[i-1] > 0 && s[i - memo[i-1] -1] == '(') {
                    memo[i] = memo[i-1] + ((i - memo[i - 1]) >= 2 ? memo[i - memo[i - 1] - 2] : 0) + 2;
                }
                res = max(res, memo[i]);
            }
        }
        return res;
    }
};