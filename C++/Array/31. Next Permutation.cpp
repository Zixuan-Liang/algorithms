#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 特殊情况，只有一个数，直接返回
        if (nums.size() == 1) return ;
        int i = nums.size() - 1;
        // 从后往前寻找，直到出现第一个非递增的数，记作x
        for (; i > 0; i--) {
            if (nums[i-1] < nums[i]) break;
        }
        // 如果从后往前数，全部都是递增序列，直接翻转整个数组
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // 否则从该尾部的递增序列中，从后往前寻找第一个比x大的数，并与x交换（可以用二分法查找优化）
            auto loc = upper_bound(nums.rbegin(), nums.rbegin()+nums.size()-i, nums[i-1]);
            swap(nums[i-1], *loc);
            // 翻转与x交换过的尾部递增序列
            reverse(nums.begin()+i, nums.end());
        }
        
    }
};