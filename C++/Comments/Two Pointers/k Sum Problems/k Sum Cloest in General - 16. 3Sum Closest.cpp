class Solution {
public:
    
    const int K = 3;

    // kSumClosest
    int kSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSumClosest(nums, target, 0, K);
    }
    
    // nums should be sorted
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