// 类似于2sum的思路，用哈希表保存前缀和出现的次数
// 计算到新的前缀和x的时候，去哈希表寻找之前等于x-k的前缀和出现次数

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for (int n : nums) {
            prefixSum += n;
            int needed = prefixSum - k;
            if (sumCount.count(needed)) {
                ans += sumCount[needed]; 
            }
            sumCount[prefixSum]++;
        }
        return ans;
    }
};