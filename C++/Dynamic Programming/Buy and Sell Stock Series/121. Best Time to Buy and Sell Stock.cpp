// 系列问题 121 122 123 188 309 714

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int currMin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - currMin);
            currMin = min(currMin, prices[i]);
        }
        return res;
    }
};