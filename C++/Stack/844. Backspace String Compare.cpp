class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        for (char c : s) {
            if (c == '#') {
                if (!stk1.empty()) stk1.pop();
            }
            else {
                stk1.push(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!stk2.empty()) stk2.pop();
            }
            else {
                stk2.push(c);
            }
        }
        return stk1 == stk2;
    }
};