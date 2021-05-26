class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prevCount = 0;
        int res = 0;
        int index = 0;
        while (index < nums.size()) {
            if (res == 0 || nums[index] != nums[res-1]) {
                nums[res++] = nums[index++];
                prevCount = 1;
            }
            else {
                if (prevCount < 2) {
                    nums[res++] = nums[index++];
                    prevCount++;
                }
                else {
                    index++;
                }
            }
        }
        return res;
    }
};