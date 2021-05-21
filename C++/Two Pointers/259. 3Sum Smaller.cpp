#include <vector>

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            twoSum(nums, i, target, res);
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int index, int target, int& res) {
        int left = index+1, right = nums.size()-1;
        while (left < right) {
            int s = nums[index] + nums[left] + nums[right];
            if (s < target) {
                res += right - left;
                left++;
            }
            else {
                right--;
            }
        }
    }
};