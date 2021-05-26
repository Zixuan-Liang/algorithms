class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0, index = 0;
        while (index < nums.size()) {
            if (res == 0 || nums[index] != nums[res-1]) {
                nums[res++] = nums[index++];
            }
            else {
                index++;
            }
        }
        return res;
    }
};