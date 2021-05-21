// INT_MAX = 2^31 - 1 = 2147483647, INT_MAX = 2^32 = 2147483648

class Solution {
public:
    bool isPalindrome(int x) {
        const int CAP = INT_MAX/10;
        if (x < 0) return false;
        int backup = x;
        int reverse = 0;
        while (x) {
            if (reverse > CAP || (reverse == CAP && x%10>=8)) return false;
            reverse = reverse * 10 + x%10;
            x /= 10;
        }
        return reverse == backup;
    }
};