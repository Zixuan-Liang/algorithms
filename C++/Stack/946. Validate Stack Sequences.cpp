class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for (int x : pushed) {
            stk.push(x);
            while (!stk.empty() && j < popped.size() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};