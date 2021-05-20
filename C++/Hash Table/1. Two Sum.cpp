#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // memo key: target-number, value: index
        unordered_map<int, int> memo;
        for (int i = 0, n = nums.size(); i < n; i++){
            int num = nums[i];
            if (memo.find(num) != memo.end()) return vector<int>{memo[num], i};
            memo[target - num] = i;
        }
        // not finding the pair
        return vector<int>{-1, -1};
    }
};