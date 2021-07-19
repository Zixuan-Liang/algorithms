class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> removed;
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            else if (s[i] == '(') {
                stack.push_back(i);
            }
            else if (stack.empty()) {
                removed.insert(i);
            }
            else {
                stack.pop_back();
            }
        }
        for (int index : stack) {
            removed.insert(index);
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (!removed.count(i)) {
                ans += s[i];
            }
        }
        return ans;
    }
};