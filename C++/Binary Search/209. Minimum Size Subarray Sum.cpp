// O(nlogn)

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
        // NNN...NNNYYY... 找出第一个Y
        while (left < right) { // 循环不变量：答案可能存在于[left, right)
            int mid = left + (right - left) / 2;
            if (attemp(target, nums, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (left > nums.size()) { // 循环打破，根据最后一个剩下的数检查答案是否存在
            return 0; 
        }
        else {
            return left;
        }
    }
};