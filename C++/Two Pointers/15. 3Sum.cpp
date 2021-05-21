#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i-1] != nums[i]) {
                twoSum(nums, i, res);
            }
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int index, vector<vector<int>>& res) {
        int left = index+1, right = nums.size()-1;
        while (left < right) {
            int sum = nums[index] + nums[left] + nums[right];
            if (sum == 0) {
                res.emplace_back(vector<int>{nums[index], nums[left], nums[right]});
                left++; right--;
                while (left < right && nums[left] == nums[left-1]) left++;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
};