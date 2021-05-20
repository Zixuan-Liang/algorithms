#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> memo;
        int res = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if (memo.find(c) != memo.end() && memo[c] >= start) {
                start = memo[c] + 1;
            }
            else {
                res = max(res, i-start+1);
            }
            memo[c] = i;
        }
        return res;
    }
};