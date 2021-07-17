class Solution {
            
public:
    
    void backtrack(vector<int>& candidates, int remain, vector<int>& comb, int start, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(comb);
            return ;
        }
        else if (remain < 0) {
            return ;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], comb, i, res);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        backtrack(candidates, target, comb, 0, res);
        return res;
    }
};