class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int prevZero = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                res = max(res, i - prevZero - 1);
                prevZero = i;
            }
        }
        res = max(res, n - prevZero - 1);
        return res;
    }
};