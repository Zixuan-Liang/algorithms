class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long lo = 1, hi = x/2+1;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            long square = mid * mid;
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