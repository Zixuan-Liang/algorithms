class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) { // 循环不变性：答案必存在于区间[low, high]
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l; // 循环打破，区间长度为1，该数即为答案
    }
};