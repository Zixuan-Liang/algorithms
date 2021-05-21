#include <stack>
#include <map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> lookup = {{']', '['}, {')', '('}, {'}', '{'}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }
            else {
                if (stk.empty() || stk.top() != lookup[c]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};