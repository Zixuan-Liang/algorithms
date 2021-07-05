#include <vector>
#include <string>
#include <cmath> // trunc
#include <numeric> // accumulate
#include <locale> // isdigit

// DFS解决所有基本计算器问题
// 复杂度：时间：O(n)，空间O(n)
class Solution {
public:
    
    unordered_set<char> operators = {'+','-','*','/'};

    // 栈顶数值和当前数值进行一次操作
    void operate(vector<int>& stack, char presign, int num) {
        if (presign == '+') {
            stack.push_back(num);
        }
        else if (presign == '-') {
            stack.push_back(-num);
        }
        else if (presign == '*') {
            stack.back() *= num;
        }
        else if (presign == '/') {
            stack.back() /= num;
        }
        else {} // raise error
    }
    
    int sum(vector<int>& stack) {
        return accumulate(stack.begin(), stack.end(), 0);
    }
    
    // DFS返回栈内所有元素的和，还有索引值（最后返回的索引值应该是字符串的长度）
    pair<int, int> dfs(string& s, int i) {
        vector<int> stack;
        int num = 0;
        char presign = '+'; // 初始化空栈，当前数值为0，符号为+
        while (i < s.size()) { // 遍历字符串
            if (isdigit(s[i])) { // 遇到数字，更新当前数值
                num = num * 10 + (s[i] - '0');
            }
            else if (operators.count(s[i])) { // 遇到操作符，对栈进行一次操作，更新当前值和符号
                operate(stack, presign, num);
                presign = s[i];
                num = 0;
            }
            else if (s[i] == '(') { // 遇到左括号，从下一个索引值开始递归调用
                auto bracket = dfs(s, i+1);
                num = bracket.first; // 递归调用返回的结果就是这对括号内的计算结果！更新当前数值为此结果
                i = bracket.second; // 同样需要更新当前索引值（更新为这对括号的右括号索引值）
            }
            else if (s[i] == ')') { // 遇到右括号，对栈再进行括号内最后一次操作，再返回栈内元素和，这对括号计算完毕
                operate(stack, presign, num);
                return {sum(stack), i};
            }
            else {
                // ignore space
            }
            i++;
        }
        return {sum(stack), i};
    }
    
    int calculate(string s) {
        s += '+'; // 输入字符串后面加一个'+'方便最后返回结果
        return dfs(s, 0).first; // 
    }
};