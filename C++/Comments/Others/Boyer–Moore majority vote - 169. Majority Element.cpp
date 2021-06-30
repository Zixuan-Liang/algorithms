// 多数投票算法，找出数组中的多数元素，贡献：常数空间
// 复杂度：时间O(n)，空间O(1)
// 注意：无论是否有多数元素，此代码均返回一个元素
// 可以再进行一次遍历，检查此元素是否真正出现了超过n/2次

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        for (int n : nums) {
            if (count == 0) { // 如果前面的数抵消了candidate，更新candidate为当前数
                candidate = n;
                count = 1;
            }
            else if (n == candidate) { // 如果当前数等于candidate，计数+1
                count++;
            }
            else { // 否则计数-1
                count--;
            }
        }

        // count = 0;
        // for (int n : nums) {
        //     if (n == candidate) {
        //         count++;
        //     }
        // }
        // return count > n/2 ? candidate : -1;

        return candidate; // 如果真的有一个多数元素x(出现次数>n/2)，最后candidate肯定是x，因为其他元素不足以将其抵消
    }
};