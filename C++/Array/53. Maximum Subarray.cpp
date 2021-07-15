class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for (int n : nums) {
            sum = max(n, sum+n); // 如果前面累加和当前相加比当前小，直接舍弃前面的累加和
            res = max(res, sum);
        }
        return res;
    }
};