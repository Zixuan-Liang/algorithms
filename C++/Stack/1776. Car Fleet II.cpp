#include <stack>

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        stack<int> stk;
        vector<double> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            int p = cars[i][0], s = cars[i][1];
            while (!stk.empty()) {
                int j = stk.top(), p2 = cars[j][0], s2 = cars[j][1];
                if (s <= s2 || 1.0 * (p2 - p) / (s - s2) >= res[j] && res[j] > 0)
                    stk.pop();
                else
                    break;
            }
            if (!stk.empty())
                res[i] = 1.0 * (cars[stk.top()][0] - p) / (s - cars[stk.top()][1]);
            stk.push(i);
        }
        return res;
    }
};