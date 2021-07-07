class Solution {
public:
    
    bool attemp(int target, vector<int>& nums, int len) {
        int sum = accumulate(nums.begin(), nums.begin()+len, 0);
        if (sum >= target) {
            return true;
        }
        for (int i = len; i < nums.size(); i++) {
            sum += nums[i] - nums[i - len];
            if (sum >= target) {
                return true;
            }
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 1, right = nums.size() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (attemp(target, nums, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (left > nums.size()) {
            return 0; 
        }
        else {
            return left;
        }
    }
};