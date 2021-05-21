// INT_MAX = 2^31 - 1 = 2147483647, INT_MAX = 2^32 = 2147483648

class Solution {
public:
    int reverse(int x) {
        const int CAP = INT_MAX/10;
        if (x == INT_MIN) return 0;
        int sign = (x>=0) ? 1 : -1;
        x = abs(x);
        int res = 0;
        while (x) {
            int digit = x%10;
            if (res > CAP) return 0;
            if (res == CAP && ((sign==1 && digit>=8) || (sign==-1 && digit==9))) return 0;
            res = res * 10 + digit;
            x = x/10;
        }
        return res * sign;
    }
};