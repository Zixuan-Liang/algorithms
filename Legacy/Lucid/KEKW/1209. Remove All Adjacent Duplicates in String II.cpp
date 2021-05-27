#include <stack>
#include <utility>

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> cStack;
        int count;
        for (char ch: s){
            count = (cStack.empty() || cStack.top().first!=ch) ? 1 : cStack.top().second+1;
            cStack.push({ch, count});
            if (cStack.top().second == k) {
                for (int i = 0; i < k; i++){
                    cStack.pop();
                }
            }
        }
        string res = "";
        while (!cStack.empty()){
            res+=cStack.top().first;
            cStack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};