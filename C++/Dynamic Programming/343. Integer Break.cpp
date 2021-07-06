class Solution {

    unordered_map<int, int> memo;

public:
    
    int helper(int n) {
        
        if (memo.count(n)) return memo[n];
        
        if (n <= 3) {
            return n;
        }
        else {
            int res = 1;
            for (int i = 2; i <= n/2+1; i++) {
                res = max(res, helper(n-i) * helper(i));
            }
            memo[n] = res;
            return res;
        }
    }
    
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        return helper(n);
    }
};