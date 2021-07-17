class Solution {
public:
    
    const int K = 3; // K可以为任意K>=2

    // 通用kSumSmaller的解决方案，复杂度：O(n^(k-1))
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSumSmaller(nums, target, 0, K);
    }
    
    // 输入数组应该已经排好序，kSumSmaller(k)递归调用kSumSmaller(k - 1)，base case为twoSumSmaller
    int kSumSmaller(vector<int>& nums, int target, int start, int k) {
        if (start + k > nums.size())
            return 0;
        if (k == 2)
            return twoSumSmaller(nums, target, start);
        int res = 0;
        for (int i = start; i <= nums.size() - k; ++i) {
            res += kSumSmaller(nums, target - nums[i], i + 1, k - 1);
        }
        return res;
    }

    // 双指针解决已排序数组的twoSumSmaller, O(n)
    int twoSumSmaller(vector<int>& nums, int target, int start) {
        int lo = start, hi = nums.size() - 1;
        int res = 0;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target) {
                res += hi - lo;
                lo++;
            }
            else {
                hi--;
            }
        }
        return res;
    }
    
};