class Solution {
public:
    int climbStairs(int n) {
        int x = 0, y = 1;
        for (int i = 0; i < n; i++) {
            tie(x, y) = pair{y, x + y};
        }
        return y;
    }
};