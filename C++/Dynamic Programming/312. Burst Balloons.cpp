struct PairHash{
    size_t operator()(const pair<int, int>& p) const {
        auto intHash = hash<int>();
        return intHash(p.first) ^ intHash(p.second);
    }
};

class Solution {
public:
    
    int helper(vector<int>& nums, int start, int end, unordered_map<pair<int, int>, int, PairHash>& dp) {
        if (end == start + 1) {
            return 0;
        }
        if (dp.count({start, end})) {
            return dp[{start, end}];
        }
        int ans = INT_MIN;
        for (int i = start + 1; i < end; i++) {
            int candidate = nums[i] * nums[start] * nums[end] + helper(nums, start, i, dp) + helper(nums, i, end, dp);
            ans = max(ans, candidate);
        }
        dp[{start, end}] = ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        unordered_set<int> allsame(nums.begin(), nums.end());
        if (allsame.size() == 1 && nums.size() >= 3) return pow(nums[0], 3) * (nums.size() - 2) + nums[0] * nums[0] + nums[0];
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        unordered_map<pair<int, int>, int, PairHash> dp;
        return helper(nums, 0, n-1, dp);
    }
};