// 真值表
// ab      x       新的ab
// 00      0       00
// 00      1       01     从出现0次变为出现1次
// 01      0       01
// 01      1       10     从出现1次变为出现2次
// 10      0       10
// 10      1       00     从出现2次变为出现3次

// 最后b就是只出现1次的数，因为所有其他数都出现3次，它们会把b归零
// 只出现1次的数才会把b的对应位置1

// 所以根据真值表得到逻辑转移：
// 新a = (~a & b & x) | (a & ~b & ~x)
// 新b = (~a & ~b & x) | (~a & b & ~x)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            tie(a, b) = pair{(~a & b & x) | (a & ~b & ~x), (~a & ~b & x) | (~a & b & ~x)};
        }
        return b;
    }
};