// s = "   -42" -> -42
// s = "4193 with words" -> 4193
// s = "words and 987" -> 0

// INT_MAX = 2^31 - 1 = 2147483647, INT_MAX = 2^32 = 2147483648

class Solution {
public:
    int myAtoi(string str) {
        const int CAP = INT_MAX/10;
        if (str.empty()) return 0;
        int i = 0, sign = 1;
        while (i + 1 < str.size() && isspace(str[i])) ++i;
        int res = 0;
        if (str[i] == '-' || str[i] == '+') sign = (str[i++]=='+') ? 1 : -1;
        while (i < str.size()) {
            if (isdigit(str[i])) {
                if (res > CAP || (res == CAP &&  str[i]-'0'>=8)) 
                    return (sign==1) ? INT_MAX : INT_MIN;
                res = 10 * res + (str[i++] - '0');
            }
            else return res * sign;
        }
        return res * sign;
    }
};