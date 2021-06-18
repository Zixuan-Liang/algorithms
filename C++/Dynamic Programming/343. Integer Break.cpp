class Solution {

    unordered_map<int, int> memo;

public:
    
    int helper(int n, int k) {

        if (memo.count(k*100+n)) return memo[k*100+n];
        
        if (k == 2 && n == 2) {
            return 1;
        }
        else if (k == 1 && n <= 3) {
            return n;
        }
        else {
            int res = 1;
            for (int i = 2; i <= n/2+1; i++) {
                res = max(res, helper(n-i, 1) * helper(i, 1));
            }
            memo[k*100+n] = res;
            return res;
        }
    }
    
    int integerBreak(int n) {
        return helper(n, 2);
    }
};