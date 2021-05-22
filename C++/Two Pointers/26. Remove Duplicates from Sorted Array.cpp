class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        int lastSeen = INT_MAX;
        for (int n : nums) {
            if (n != lastSeen) {
                lastSeen = n;
                nums[res] = n;
                res++;
            }
        }
        return res;
    }
};