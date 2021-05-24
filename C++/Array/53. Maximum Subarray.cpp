class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxVal = INT_MIN;
        for (int n : nums) maxVal = max(maxVal, n);
        if (maxVal <= 0) return maxVal;
        
        int res = 0;
        int posBlock = 0, negBlock = 0, merge = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0) {
                while (i < nums.size() && nums[i] > 0) {
                    posBlock += nums[i++];
                }
                res = max(res, posBlock);
            }
            else {
                negBlock = 0;
                while (i < nums.size() && nums[i] <= 0) {
                    negBlock += nums[i++];
                }
                merge = posBlock + negBlock;
                posBlock = merge > 0 ? merge : 0;
            }
        }
        return res;
    }
};