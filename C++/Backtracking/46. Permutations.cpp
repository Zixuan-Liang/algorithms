class Solution {
public:
    
    void backtrack(vector<int>& nums, unordered_set<int>& seen, vector<int>& perm, vector<vector<int>>& res) {
        if (perm.size() == nums.size()) res.push_back(perm);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (seen.find(nums[i]) == seen.end()) {
                    seen.insert(nums[i]);
                    perm.push_back(nums[i]);
                    backtrack(nums, seen, perm, res);
                    perm.pop_back();
                    seen.erase(nums[i]);
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        unordered_set<int> seen;
        backtrack(nums, seen, perm, res);
        return res;
    }
};