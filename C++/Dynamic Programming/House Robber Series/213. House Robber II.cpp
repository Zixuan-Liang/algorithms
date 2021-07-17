class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        return max(rob_198_House_Robber(nums, 0, n-2), rob_198_House_Robber(nums, 1, n-1));
    }
    
    int rob_198_House_Robber(vector<int>& nums, int start, int end) {
        int dp1 = 0, dp2 = 0;
        for (int i = start; i <= end; i++) {
            int n = nums[i];
            tie(dp1, dp2) = pair{dp2, max(n + dp1, dp2)};
        }
        return dp2;
    }
};