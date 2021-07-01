class Solution {
public:
    
    // 84的答案
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        
        vector<int> dp(n, 0);
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j]+1 : 0;
            }
            res = max(res, largestRectangleArea(dp));
        }
        return res;
    }
};