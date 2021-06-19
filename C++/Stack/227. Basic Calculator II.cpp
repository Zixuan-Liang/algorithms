#include <numeric>

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        vector<int> stack;
        int num = 0;
        char op = '+';
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = (num * 10) + (c - '0');
            }
            if (!isdigit(c) && !iswspace(c) || i == n - 1) {
                if (op == '-')
                    stack.push_back(-num);
                else if (op == '+')
                    stack.push_back(num);
                else if (op == '*')
                    stack.back() *= num;
                else if (op == '/')
                    stack.back() /= num;
                op = c;
                num = 0;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};

// Not using stack, O(n) time O(1) space, remember lastNum and currNum and combine them
// if * or / comes up.
// class Solution {
// public:
//     int calculate(string s) {
//         int length = s.length();
//         if (length == 0) return 0;
//         int currentNumber = 0, lastNumber = 0, result = 0;
//         char sign = '+';
//         for (int i = 0; i < length; i++) {
//             char currentChar = s[i];
//             if (isdigit(currentChar)) {
//                 currentNumber = (currentNumber * 10) + (currentChar - '0');
//             }
//             if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
//                 if (sign == '+' || sign == '-') {
//                     result += lastNumber;
//                     lastNumber = (sign == '+') ? currentNumber : -currentNumber;
//                 } else if (sign == '*') {
//                     lastNumber = lastNumber * currentNumber;
//                 } else if (sign == '/') {
//                     lastNumber = lastNumber / currentNumber;
//                 }
//                 sign = currentChar;
//                 currentNumber = 0;
//             }
//         }
//         result += lastNumber;
//         return result;  
//     }
// };