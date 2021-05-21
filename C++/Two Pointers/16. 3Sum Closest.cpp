#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // residual
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            twoSum(nums, i, target, res);
            if (res == 0) break;
        }
        return res + target;
    }
    
    void twoSum(vector<int>& nums, int index, int target, int& res) {
        int left = index+1, right = nums.size()-1;
        while (left < right) {
            int s = nums[index] + nums[left] + nums[right];
            if (abs(s-target) < abs(res)) res = s - target;
            if (s - target == 0) {
                break;
            }
            else if (s - target < 0) {
                left++;
            }
            else {
                right--;
            }
        }   
    }
};