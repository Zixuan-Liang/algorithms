class Solution {
public:
    
    const int K = 3; // K可以为任意K>=2

    // 通用kSumClosest的解决方案，复杂度：O(n^(k-1))
    int kSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSumClosest(nums, target, 0, K);
    }
    
    // 输入数组应该已经排好序，kSumClosest(k)递归调用kSumClosest(k - 1)，base case为twoSumClosest
    int kSumClosest(vector<int>& nums, int target, int start, int k) {
        if (start == nums.size() - k)
            return accumulate(nums.end() - k, nums.end(), 0);
        if (k == 2)
            return twoSumClosest(nums, target, start);
        int res;
        int diff = INT_MAX;
        for (int i = start; i <= nums.size() - k; ++i) {
            int candidate = nums[i] + kSumClosest(nums, target - nums[i], i + 1, k - 1);
            if (candidate == target) return target;
            if (abs(candidate - target) < diff) {
                diff = abs(candidate - target);
                res = candidate;
            }
        }
        return res;
    }

    // 双指针解决已排序数组的twoSumClosest, O(n)
    int twoSumClosest(vector<int>& nums, int target, int start) {
        int diff = INT_MAX;
        int lo = start, hi = nums.size() - 1;
        int res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (abs(sum - target) < diff) {
                diff = abs(sum - target);
                res = sum;
            }
            if (sum < target)
                ++lo;
            else if (sum > target)
                --hi;
            else {
                return target;
            }      
        }
        return res;
    }
    
};