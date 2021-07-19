#include <stack>
#include <utility>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<pair<int, int>> monoStack;
        for (int i = 0; i < T.size(); i++){
            
            while (!monoStack.empty() && monoStack.top().second<T[i]){
                pair<int, int> top = monoStack.top();
                res[top.first] = i - top.first;
                monoStack.pop();
            }
            monoStack.push(make_pair(i, T[i]));

        }
        return res;
    }
};