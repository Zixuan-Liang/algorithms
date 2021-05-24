// Similiar to 45
// If use DP like 45, LTE

class Solution {
public:

    // 从下往上的贪心算法
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int maxReach = 0;
        for (int i = 0; i <= maxReach; i++) {
            maxReach = max(maxReach, i+nums[i]);
            if (maxReach >= len-1) return true;
        }
        return false;
    }

    // 从上往下的贪心算法
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};