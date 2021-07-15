class Solution {
    
    unordered_set<string> words;
    
public:
    
    void backtrack(string s, int index, string curr, vector<string>& ans) {
        if (index == s.size()) {
            ans.emplace_back(curr);
        }
        else {
            for (int len = 1; len <= s.size() - index; len++) {
                if (words.count(s.substr(index, len))) {            
                    backtrack(s, index + len, curr + (curr=="" ? "" : " ") + s.substr(index, len), ans);
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        words = unordered_set<string>(wordDict.begin(), wordDict.end());
        string curr = "";
        backtrack(s, 0, curr, ans);
        return ans;
    }
};