class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto lower = lower_bound(nums.begin(), nums.end(), 0);
        int i = lower - nums.begin();
        int j = i - 1;
        vector<int> res;
        while (j >= 0 && i < nums.size()) {
            int a = pow(nums[j], 2);
            int b = pow(nums[i], 2);
            if (a < b) {
                res.push_back(a);
                j--;
            }
            else {
                res.push_back(b);
                i++;
            }
        }
        while (j >= 0) res.push_back(pow(nums[j--], 2));
        while (i < nums.size()) res.push_back(pow(nums[i++], 2));
        return res;
    }
};