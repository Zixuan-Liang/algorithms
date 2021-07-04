class Solution {
public:
    
    const int K = 3; // K可以为任意K>=2

    // 通用kSum的解决方案，复杂度：O(n^(k-1))
    vector<vector<int>> threeSum(vector<int>& nums, int target = 0) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, K);
    }

    // 输入数组应该已经排好序，kSum(k)递归调用kSum(k - 1)，base case为2Sum
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        if (start + k > nums.size()) {
            return {};
        }
        if (k == 2)
            return twoSum(nums, target, start);
        vector<vector<int>> res;
        for (int i = start; i <= nums.size() - k; ++i)
            if (i == start || nums[i - 1] != nums[i])
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));   
                }
        return res;
    }

    // 双指针解决已排序数组的2Sum, O(n)
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target)
                ++lo;
            else if (sum > target)
                --hi;
            else {
                res.push_back({nums[lo++], nums[hi--]});
                while (lo < hi && nums[lo] == nums[lo-1]) lo++;
            }      
        }
        return res;
    }
};