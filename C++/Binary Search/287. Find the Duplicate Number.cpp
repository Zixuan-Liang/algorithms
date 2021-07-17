//       时间    空间
// 排序  nlogn    1
// 哈希    n      n
// 二分  nlogn    1
// Floyd's Tortoise and Hare (Cycle Detection) 最优 O(n) + O(1)，而且不修改原数组

// 满足：不修改原数组（排序做法修改了原数组），常数空间（哈希表做法用了线性空间）
// 二分查找 O(nlogn) + O(1)
class Solution {
public:

    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size() - 1;
        int low = 1, high = n;
        while (low < high) { // 循环不变量，答案必存在于[low, high]
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int n : nums) count += n <= mid; // 数多少个数小于或等于当前pivot
            if (count > mid) { // 往左查找，保持循环不变量：答案必存在于[low, high]
                high = mid;
            }
            else {
                low = mid + 1; // 往右查找，保持循环不变量：答案必存在于[low, high]
            }
        }
        return low;
    }
    
};