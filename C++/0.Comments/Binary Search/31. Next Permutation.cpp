#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return ;
        int i = nums.size() - 1;
        for (; i > 0; i--) {
            if (nums[i-1] < nums[i]) break;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            auto loc = upper_bound(nums.rbegin(), nums.rbegin()+nums.size()-i, nums[i-1]);
            swap(nums[i-1], *loc);
            reverse(nums.begin()+i, nums.end());
        }
        
    }
};