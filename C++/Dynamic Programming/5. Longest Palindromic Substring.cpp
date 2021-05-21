// This DP solution is O(n^2) in time, O(n) in space.
// Interesting solution: Manacher's algorithm, O(n) in time.

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        if (n == 2) return s[0]==s[1] ? s : string(1, s[0]);
        int memo[2][n];
        int subStrLen = 1, endIdx = 0;
        // One character
        for (int i = 0; i < n; i++) memo[1][i] = 1;
        // Two characters
        for (int i = 1; i < n; i++) {
            if (s[i-1] == s[i]) {
                subStrLen = 2;
                endIdx = i;
                memo[0][i] = 1;
            }
            else {
                memo[0][i] = 0;
            }
        }
        // Starting from 3 characters up to n characters
        for (int i = 3; i <= n; i++) {
            // row 0 if even, row 1 if odd
            int row = i%2;
            // Index of character in s: from n-1 down to i-1
            for (int j = n-1; j >= i-1; j--) {
                memo[row][j] = 0;
                if (memo[row][j-1] == 1 && s[j] == s[j-i+1]) {
                    memo[row][j] = 1;
                    subStrLen = i;
                    endIdx = j;
                }
            }
        }
        return s.substr(endIdx-subStrLen+1, subStrLen);
    }
};