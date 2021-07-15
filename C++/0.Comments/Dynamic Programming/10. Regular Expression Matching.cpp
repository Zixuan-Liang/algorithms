struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        auto intHash = hash<int>();
        return intHash(p.first) ^ intHash(p.second);
    }  
};

class Solution {
public:
    
    unordered_map<pair<int, int>, bool, PairHash> dp;
    
    bool helper(string& s, string& p, int i, int j) {
        if (!dp.count({i, j})) {
            bool res;
            if (j == p.size()) {
                res = i == s.size();
            }
            else {
                bool firstCharMatched = i < s.size() && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    bool matchZero = helper(s, p, i, j + 2);
                    bool matchMore = firstCharMatched && helper(s, p, i + 1, j);
                    res = matchZero || matchMore;
                }
                else {
                    res = firstCharMatched && helper(s, p, i + 1, j + 1);
                }
            }
            dp[{i, j}] = res;
        }
        return dp[{i, j}];
    }
    
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
};