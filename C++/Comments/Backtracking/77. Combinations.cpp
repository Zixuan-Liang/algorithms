class Solution {
public:
    
    void backtrack(int n, int k, vector<vector<int>>& res, vector<int>& comb, int start) {
        if (comb.size() == k) {
            res.push_back(comb);
        }
        else {
            for (int i = start; i <= n; i++) {
                    comb.push_back(i);
                    backtrack(n, k, res, comb, i+1);
                    comb.pop_back();
                }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(n, k, res, comb, 1);
        return res;
    }
};