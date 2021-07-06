class Solution {
public:
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& comb, int start) {
        res.push_back(comb);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1]) continue;
            comb.push_back(nums[i]);
            backtrack(nums, res, comb, i+1);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(begin(nums), end(nums));
        backtrack(nums, res, comb, 0);
        return res;
    }
};