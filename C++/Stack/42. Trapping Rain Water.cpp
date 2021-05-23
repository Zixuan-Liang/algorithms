#include <stack>

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        // 单调栈，栈顶为最小元素，存储高度、索引
        stack<pair<int,int>> mono;
        // 遍历数组
        for (int i = 0; i < height.size(); i++) {
            int h = height[i];
            // 小于栈顶，直接push
            if (mono.empty() || mono.top().first > h) mono.push({h, i});
            else {
                // 否则一直pop，直到小于栈顶为止
                int leftH = mono.top().first;
                while (!mono.empty() && mono.top().first <= h) {
                    // 每pop一个，就算一段容积，（例子：4,2,0,3，算2，0，3之间的容积）
                    // 高度以左边为准 （因为栈顶较矮）
                    res += (mono.top().first - leftH) * (i - mono.top().second - 1);
                    leftH = mono.top().first;
                    mono.pop();
                }
                // 如果栈非空，还要算一段容积 （例子：4,2,0,3，pop了0和2后，算4和3之间的容积）
                // 注意此时高度以右边为准 （此时栈顶已比右边高）
                if (!mono.empty()) res += (h - leftH) * (i - mono.top().second - 1);
                mono.push({h, i});
            }
        }
        return res;
    }
};