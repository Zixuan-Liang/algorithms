class Solution {
    
    vector<vector<char>> lookup = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    
public:
    
    void backtrack(string& digits, int i, vector<string>& ans, string& candidate) {
        if (i == digits.size()) {
            ans.push_back(candidate);
        }
        else {
            for (char c : lookup[digits[i] - '2']) {
                candidate.push_back(c);
                backtrack(digits, i+1, ans, candidate);
                candidate.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> ans;
        string candidate = "";
        backtrack(digits, 0, ans, candidate);
        return ans;
    }
};