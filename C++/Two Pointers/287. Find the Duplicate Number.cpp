//       时间    空间
// 排序  nlogn    1
// 哈希    n      n
// 二分  nlogn    1

// Floyd's Tortoise and Hare (Cycle Detection) 最优 O(n) + O(1)，而且不修改原数组
class Solution {
public:

    int findDuplicate(vector<int>& nums)
    {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
    
};