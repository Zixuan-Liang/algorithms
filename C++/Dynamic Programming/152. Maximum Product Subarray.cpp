class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int res = maxSoFar;
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int tempMax = max({curr, maxSoFar * curr, minSoFar * curr});
            minSoFar = min({curr, maxSoFar * curr, minSoFar * curr});
            maxSoFar = tempMax;
            res = max(res, maxSoFar);
        }
        return res;
    }
};