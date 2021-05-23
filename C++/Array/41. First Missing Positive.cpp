#include <algorithm>

// 算法复杂度：线性，大循环里每个元素最多只处理2次

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        int i = 0, x;
        // 答案肯定在1-n之间
        // 遍历数组，最后我们希望如果某数字x出现过，我们只让它出现一次，并放在x-1的索引位置
        // 最后满足nums[x-1] != x的最小x就是答案
        while (i < n) {
            x = nums[i];
            // 条件1：索引所在数字就是索引+1，
            // 或索引所在数字超过答案范围，
            // 或该数字已经出现在该出现的位置(x-1)，don't care，直接进入下一次循环
            if (x == i+1 || x <= 0 || x > n || x == nums[x-1]) {
                i++;
            }
            else {
                // 条件2：如果索引所在数字在答案范围内，把它和该出现的位置上的数字置换，
                // 一直循环，直到索引所在位置满足条件1
                swap(nums[i], nums[x-1]);
            }
        }
        i = 0;
        while (i < n) {
            // 满足nums[x-1] != x的最小x就是答案
            if (nums[i] != i+1) return i+1;
            i++;
        }
        return n+1;
    }
};