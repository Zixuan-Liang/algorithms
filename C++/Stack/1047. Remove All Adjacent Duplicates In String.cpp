#include <deque>

class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> stk;
        for (char c : s) {
            if (!stk.empty() && stk.back() == c) {
                stk.pop_back();
            }
            else {
                stk.push_back(c);
            }
        }
        
        string res = "";
        while (!stk.empty()) {
            res += stk.front();
            stk.pop_front();
        }
        
        return res;
    }
};