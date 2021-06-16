class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> res = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            int money = max(nums[i] + res[i], res[i+1]);
            res.push_back(money);
        }
        return res.back();
    }
};