class Solution {
public:
    
    int helper(vector<int>& nums, int index, unordered_map<int, int>& memo) {
        if (memo.find(index) == memo.end()) {
            int res = INT_MAX;
            if (index >= nums.size() - 1) {
                res = 0;
            }
            else if (nums[index] == 0) {
                res = INT_MAX;
            }
            else {
                for (int i = 1; i <= nums[index]; i++) {
                    int candidate = helper(nums, index+i, memo);
                    if (candidate != INT_MAX) {
                        res = min(res, candidate+1);
                    }
                }
            }
            memo[index] = res;
        }
        return memo[index];
    }
    
    int jump(vector<int>& nums) {
        unordered_map<int, int> memo;
        return helper(nums, 0, memo);
    }
};