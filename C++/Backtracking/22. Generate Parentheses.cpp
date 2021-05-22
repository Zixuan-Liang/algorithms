class Solution {
        
public:
    void helper(string s, int open, int close, int n, vector<string>& res) {
        if (s.size() == 2*n && open == n && close == n) {
            res.emplace_back(s);
        }
        if (open+1 <= n) {
            helper(s+"(", open+1, close, n, res);
        }
        if (close+1 <= n && open>close){
            helper(s+")", open, close+1, n, res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", 0, 0, n, res);
        return res;
    }
};