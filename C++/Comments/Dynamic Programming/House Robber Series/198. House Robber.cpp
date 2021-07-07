class Solution {
public:
    int rob(vector<int>& nums) {
        int dp1 = 0, dp2 = 0;
        for (int n : nums) {
            tie(dp1, dp2) = pair{dp2, max(n + dp1, dp2)};
        }
        return dp2;
    }
};