class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long lo = 1, hi = x/2+1;
        long mid;
        long square;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            square = mid * mid;
            if (square == x) {
                return mid;
            }
            else if (square < x) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo - 1;
    }
};