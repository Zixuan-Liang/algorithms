class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 有限状态机，卖出转移至重置，保持可转移至保持或卖出，重置可转移至重置或保持
        int sold = INT_MIN, held = INT_MIN, reset = 0;
        for (int p : prices) {
            int preSold = sold;
            sold = held + p;
            held = max(held, reset - p);
            reset = max(reset, preSold);
        }
        return max(sold, reset);
    }
};