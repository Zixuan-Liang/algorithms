class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n) {
            while (right + 1 < n && (right == left || nums[right + 1] - nums[right] == nums[right] - nums[right - 1])) {
                right++;
            }
            ans += (right - left) * (right - left - 1) / 2;
            left = right;
            if (right == n - 1) break;
        }
        return ans;
    }
};