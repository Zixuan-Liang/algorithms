// 基于46的答案修改
// 将数组变成不重复的，并用一个哈希表存储元素可使用次数，
// 然后backtrack的时候要比较元素已使用次数和可使用次数

class Solution {
public:
    
    void backtrack(int n, vector<int>& nums, unordered_map<int, int>& seen, vector<int>& perm, vector<vector<int>>& res, unordered_map<int, int>& count) {
        if (perm.size() == n) res.push_back(perm);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (seen.find(nums[i]) == seen.end() || seen[nums[i]] < count[nums[i]]) {
                    seen[nums[i]]++;
                    perm.push_back(nums[i]);
                    backtrack(n, nums, seen, perm, res, count);
                    perm.pop_back();
                    seen[nums[i]]--;
                }
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        unordered_map<int, int> seen;
        
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;
        
        vector<int> uniqueNums;
        for (auto& ele : count) uniqueNums.push_back(ele.first);
        
        backtrack(nums.size(), uniqueNums, seen, perm, res, count);
        return res;
    }
};