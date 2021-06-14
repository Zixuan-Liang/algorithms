class Solution {
    
    int a;
    int b;
    int c;
    
public:
    
    int f(int x) {
        return a * x * x + b * x + c;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        vector<int> res;
        this->a = a; this->b = b; this->c = c;
        
        if (a == 0) {
            if (b >= 0) {
                for (int n : nums)
                    res.push_back(f(n));
            }
            else {
                for (auto it = nums.rbegin(); it != nums.rend(); it++)
                    res.push_back(f(*it));
            }
            return res;
        }
        
        double peak = -1.0 * b / 2 / a;
        auto upper = upper_bound(nums.begin(), nums.end(), peak);
        int right = upper - nums.begin(), left = (--upper) - nums.begin();
        
        while (left >= 0 && right < nums.size()) {
            int lAns = f(nums[left]), rAns = f(nums[right]);
            if (a > 0 && lAns < rAns || a < 0 && lAns > rAns) {
                res.push_back(lAns);
                left--;
            }
            else {
                res.push_back(rAns);
                right++;
            }
        }
        while (left >= 0) res.push_back(f(nums[left--]));
        while (right < nums.size()) res.push_back(f(nums[right++]));
        if (a < 0) reverse(res.begin(), res.end());
        return res;
    }
};

