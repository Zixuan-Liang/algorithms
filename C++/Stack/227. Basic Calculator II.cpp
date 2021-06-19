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
