// Dutch National Flag Problem

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size()-1, curr = 0;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[p0], nums[curr]);
                p0++;
                curr++;
            }
            else if(nums[curr] == 2) {
                swap(nums[p2], nums[curr]);
                p2--;
            }
            else {
                curr++;
            }
        }
    }
};