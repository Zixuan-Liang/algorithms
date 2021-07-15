class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) { // 循环不变性，答案必存在于区间[low, high]
            if (nums[low] < nums[high]) {
                return nums[low];
            }
            int mid = low + (high - low) / 2;
            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low]; // 循环打破，区间长度为1，该值即为答案
    }
};