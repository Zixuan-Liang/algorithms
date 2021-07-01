#include <vector>
#include <string>
#include <cmath> // trunc
#include <numeric> // accumulate
#include <locale> // isdigit

class Solution {
public:
    
    void operate(vector<int>& stack, char presign, int num) {
        if (presign == '+') {
            stack.push_back(num);
        }
        else if (presign == '-') {
            stack.push_back(-num);
        }
        else if (presign == '*') {
            int tmp = stack.back() * num;
            stack.pop_back();
            stack.push_back(tmp);
        }
        else if (presign == '/') {
            int tmp = trunc(stack.back() / num);
            stack.pop_back();
            stack.push_back(tmp);
        }
        else {
            // raise error;
        }
    }
    
    int sum(vector<int>& stack) {
        return accumulate(stack.begin(), stack.end(), 0);
    }
    
    pair<int, int> dfs(string& s, int i) {
        vector<int> stack;
        int num = 0;
        char presign = '+';
        while (i < s.size()) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
                operate(stack, presign, num);
                presign = s[i];
                num = 0;
            }
            else if (s[i] == '(') {
                auto tmp = dfs(s, i+1);
                num = tmp.first;
                i = tmp.second;
            }
            else if (s[i] == ')') {
                operate(stack, presign, num);
                return {sum(stack), i};
            }
            i++;
        }
        return {sum(stack), i};
    }
    
    int calculate(string s) {
        s.push_back('+');
        return dfs(s, 0).first;
    }
};