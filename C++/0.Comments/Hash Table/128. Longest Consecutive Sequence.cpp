class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int ans = 0;
        for (int n : uset) {
            if (!uset.count(n - 1)) {
                int streak = 0;
                int curr = n;
                while (uset.count(curr)) {
                    streak++; curr++;
                }
                ans = max(ans, streak);
            }
        }
        return ans;
    }
};