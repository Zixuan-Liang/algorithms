class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0;
        for (int n : nums) sum += n;
        int f = 0;
        for (int i = 0; i < nums.size(); i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = nums.size() - 1; i > 0; i--) {
            f += sum - nums[i] * nums.size();
            res = max(res, f);
        }
        return res;
    }
};

// f(i+1) = f(i) + sum(Array) -  last element * array.length