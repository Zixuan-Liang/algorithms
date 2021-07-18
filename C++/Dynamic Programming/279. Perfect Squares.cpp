class Solution {
public:
    
    int helper(int n, unordered_map<int, int>& memo) {
        if (!memo.count(n)) {
            int res = INT_MAX;
            int sqrtN = floor(pow(n, 0.5));
            if (sqrtN * sqrtN == n) {
                res = 1;
            }
            else {
                for (int i = sqrtN; i >= 1; i--) {
                    res = min(res, 1 + helper(n - i*i, memo));
                }
            }
            memo[n] = res;
        }
        return memo[n];
    }
    
    int numSquares(int n) {
        unordered_map<int, int> memo;
        return helper(n, memo);
    }
};