#include <unordered_map>

struct PairHash{
    std::size_t operator()(const pair<int, int>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1^h2;
    }
};

class Solution {
    unordered_map<pair<int, int>, bool, PairHash> memo;
    string text;
    string pattern;
    
public:
    bool helper(int i, int j) {
        bool res;
        bool firstMatch;
        if (memo.find({i, j}) == memo.end()) {
            if (j == pattern.size()) {
                res = i == text.size();
            }
            else {
                firstMatch = i < text.size() && (pattern[j] == text[i] || pattern[j] == '.');
                if (j+1 < pattern.size() && pattern[j+1] == '*') {
                    res = helper(i, j+2) || (firstMatch && helper(i+1, j));
                }
                else {
                    res = firstMatch && helper(i+1, j+1);
                }
            }
            memo[{i, j}] = res;
        }
        return memo[{i, j}];
    }
    
    bool isMatch(string s, string p) {
        text = s;
        pattern = p;
        return helper(0, 0);
    }
};