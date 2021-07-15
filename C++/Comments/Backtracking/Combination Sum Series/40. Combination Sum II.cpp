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
            if (i != start && candidates[i] == candidates[i - 1]) continue; // 比39. Combination Sum多这一行，避免重复组合
            comb.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], comb, i+1, res);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, comb, 0, res);        
        return res;
    }
};