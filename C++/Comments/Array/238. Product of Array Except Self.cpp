class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prefixL = 1;
        for (int n : nums) {
            prefixL *= n;
            ans.push_back(prefixL);
        }
        int prefixR = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            ans[i] = prefixR * ans[i - 1];
            prefixR *= nums[i];
        }
        ans[0] = prefixR;
        return ans;
    }
};