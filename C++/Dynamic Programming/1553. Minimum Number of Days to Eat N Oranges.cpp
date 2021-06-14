class Solution {
    
    unordered_map<int, int> memo;
    
public:
    
    int minDays(int n) {
        if (n <= 1)
            return n;
        if (memo.find(n) == memo.end())
            memo[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return memo[n];
    }
};