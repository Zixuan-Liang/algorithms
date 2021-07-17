// #define LL long long
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& nums, int m) {
        LL l = 0, r = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            r += nums[i];
            if (l < nums[i]) {
                l = nums[i];
            }
        }
        LL ans =  r;
        while (l <= r) { // 循环不变量：答案必存在于[left, right]中
            LL mid = (l + r) >> 1;
            LL sum = 0;
            int cnt = 1;            
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt ++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m) { // 能满足当前限制，更新答案，往左查找
                ans = min(ans, mid);
                r = mid - 1;
            } else { // 不能满足当前限制，需要提高下限
                l = mid + 1;
            }
        }
        return ans; // 循环打破，区间长度为0，答案已经在循环中line 28逐渐更新为最优
    }
};