class Solution {
public:
    
    bool helper(string& s, unordered_set<string>& words, int start, unordered_map<int, bool>& dp) {
        if (start == s.size()) {
            return true;
        }
        if (dp.count(start)) {
            return dp[start];
        }
        for (int len = 1; len <= s.size() - start; len++) {
            if (words.count(s.substr(start, len))) {
                if (helper(s, words, start+len, dp)) {
                    dp[start] = true;
                    return true;
                }
            }
        }
        dp[start] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> dp;
        return helper(s, words, 0, dp);
    }

};