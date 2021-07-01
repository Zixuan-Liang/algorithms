class Solution {
public:

    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size() - 1;
        int low = 1, high = n + 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int n : nums) count += n <= mid;
            if (count > mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
    
};