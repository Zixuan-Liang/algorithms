class Solution {
        
public:
    void backtrack(string s, int open, int close, int n, vector<string>& res) {
        if (s.size() == 2*n && open == n && close == n) {
            res.emplace_back(s);
        }
        if (open+1 <= n) {
            backtrack(s+"(", open+1, close, n, res);
        }
        if (close+1 <= n && open>close){
            backtrack(s+")", open, close+1, n, res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }
};