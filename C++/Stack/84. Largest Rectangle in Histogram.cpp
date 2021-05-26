#include <algorithm>

// 枚举每个条的高为矩阵的高，找出每个条左右两边离它最近的小于它的条作为边界，以此求出矩阵宽
// 用单调栈数据结构求每个条的左右边界，每次弹出的时候更新答案

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // index, height
        stack<pair<int, int>> mono;
        // 哨兵
        mono.push({-1, -1});
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            while (mono.top().second >= h) {
                int height = mono.top().second;
                mono.pop();
                res = max(res, height * (i - mono.top().first - 1));
            }
            mono.push({i, h});
        }
        while (mono.size() > 1) {
            int height = mono.top().second;
            mono.pop();
            int candidate = height * (heights.size() - mono.top().first - 1);
            res = max(res, candidate);
        }
        return res;
    }
};