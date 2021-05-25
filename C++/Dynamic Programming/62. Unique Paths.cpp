class Solution {
public:
    
    int helper(int x, int y, int m, int n, map<pair<int, int>, int>& memo) {
        if (memo.find({x, y}) == memo.end()) {
            int res;
            if (x == 0 || y == 0) {
                res = 1;
            }
            else {
                res = helper(x-1, y, m, n, memo) + helper(x, y-1, m, n, memo);
            }
            memo[{x, y}] = res;
        }
        return memo[{x, y}];
    }
    
    int uniquePaths(int m, int n) {
        map<pair<int, int>, int> memo;
        return helper(m-1, n-1, m, n, memo);
    }
};