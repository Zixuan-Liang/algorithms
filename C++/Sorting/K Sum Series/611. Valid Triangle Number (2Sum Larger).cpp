class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(begin(nums), end(nums), greater<int>());
        int ans = 0;
        for (int i = 0; i <= nums.size() - 3; i++) {
            ans += twoSumLarger(nums, nums[i], i + 1);
        }
        return ans;
    }
    
    int twoSumLarger(vector<int>& nums, int target, int start) {
        int low = start, high = nums.size() - 1;
        int ans = 0;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum > target) {
                ans += high - low;
                low++;
            }
            else {
                high--;
            }
        }
        return ans;
    }
};