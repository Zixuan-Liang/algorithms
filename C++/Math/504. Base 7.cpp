class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        int sign = (num >= 0) ? 1 : -1;
        num = abs(num);
        string res;
        while (num > 0) {
            int digit = num % 7;
            res += to_string(digit);
            num /= 7;
        }
        if (sign == -1) res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};