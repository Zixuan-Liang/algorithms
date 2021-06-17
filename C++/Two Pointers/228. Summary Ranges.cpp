class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (j+1 < n && nums[j+1] == nums[j] + 1) {
                j++;
            }
            string range = to_string(nums[i]);
            if (i != j)
                range += "->" + to_string(nums[j]);
            res.push_back(range);
            j++; i = j;
        }
        return res;
    }
};