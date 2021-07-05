#include <unordered_map>

struct PairHash{
    std::size_t operator()(const pair<int, int>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1^h2;
    }
};

// 如果用unordered_map会超时
// 本题类似10

class Solution {
    
public:
    
    bool helper(int i, int j, string& text, string& pattern, map<pair<int, int>, bool>& memo) {
        bool res;
        if (!memo.count({i, j})) {
            if (j == pattern.size()) {
                res = i == text.size();
            }
            else {
                if (pattern[j] == '*') {
                    res = helper(i, j+1, text, pattern, memo) || helper(i+1, j+1, text, pattern, memo);
                    if (i < text.size()) res = res || helper(i+1, j, text, pattern, memo);
                }
                else if (i < text.size() && (text[i] == pattern[j] || pattern[j] == '?')) {
                    res = helper(i+1, j+1, text, pattern, memo);
                }
                else {
                    res = false;
                }
            }
            memo[{i, j}] = res;
        }
        return memo[{i, j}];
    }
    
    bool isMatch(string s, string p) {
        map<pair<int, int>, bool> memo;
        return helper(0, 0, s, p, memo);
    }
};