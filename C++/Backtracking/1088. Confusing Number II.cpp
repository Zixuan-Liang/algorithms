class Solution {
public:
    
    long rotate(long x) {
        long res = 0;
        while (x) {
            long digit = x % 10;
            if (digit == 6) digit = 9;
            else if (digit == 9) digit = 6;
            res = res * 10 + digit;
            x /= 10;
        }
        return res;
    }
    
    void backtrack(long n, long x, int& res, vector<long>& valid) {
        if (x > n) {
            return ;
        }
        if (rotate(x) != x) {
            res++;
        }
        for (long i : valid) {
            if (x == 0 && i == 0) continue;
            x = x * 10 + i;
            backtrack(n, x, res, valid);
            x = x/10;
        }
    }
    
    int confusingNumberII(int n) {
        int res = 0;
        vector<long> valid = {0, 1, 6, 8, 9};
        backtrack(n, 0, res, valid);
        return res;
    }
};