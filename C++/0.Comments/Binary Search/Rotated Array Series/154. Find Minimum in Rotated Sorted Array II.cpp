class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            if (nums[low] < nums[high]) {
                return nums[low];
            }
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[low]) {
                low = mid + 1;
            }
            else if (nums[mid] < nums[low]) {
                high = mid;
            }
            else {
                low++;
            }
        }
        return nums[low];
    }
};