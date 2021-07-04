class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target)
                ++lo;
            else if (sum > target)
                --hi;
            else {
                return {lo+1, hi+1};
            }      
        }
        return {-1, -1};
    }
    
};