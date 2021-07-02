#include <deque>

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<vector<int>> mono;
        int res = INT_MIN;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            while (!mono.empty() && mono.front()[0] < x - k) {
                mono.pop_front();
            }
            if (!mono.empty()) {
                res = max(res, mono.front()[1] + x + y);
            }
            while (!mono.empty() && mono.back()[1] <= y - x) {
                mono.pop_back();
            }
            mono.push_back({x, y - x});
        }
        return res;
    }
};