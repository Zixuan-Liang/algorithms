class Solution {
public:
    int climbStairs(int n) {
        int x = 0, y = 1;
        int temp;
        for (int i = 0; i < n; i++) {
            temp = y;
            y = x + y;
            x = temp;
        }
        return y;
    }
};