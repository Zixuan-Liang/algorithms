class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            res.emplace_back(res.back() + nums[i]);
        }
        return res;
    }
};