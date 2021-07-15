class Solution {
public:
    
    bool isPalindrome(string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void backtrack(vector<vector<string>>& res, string& s, int start, vector<string>& vec) {
        if (start >= s.length()) res.push_back(vec);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                // add current substring in the currentList
                vec.push_back(s.substr(start, end - start + 1));
                backtrack(res, s, end + 1, vec);
                // backtrack and remove the current substring from currentList
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> vec;
        backtrack(res, s, 0, vec);
        return res;
    }
};
