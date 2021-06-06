#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                int temp;
                if (t == "+") {
                    temp = y + x;
                }
                else if (t == "-") {
                    temp = y - x;
                }
                else if(t == "*") {
                    temp = y * x;
                }
                else {
                    temp = y / x;
                }
                stk.push(temp);
            }
            else {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};