class Solution {
public:
    
    // 2k>=n, fall back to question 122, can buy or sell with no limit
    int maxProfitNoLimit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i-1]);
        }
        return res;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        if (k == 0) return 0;
        else if (2 * k >= n) return maxProfitNoLimit(prices);
        else {
            
            // memo[i][j][0]: max profit at the end of day i, with j remaining transactions, status is not holding stack
            // memo[i][j][1]: max profit at the end of day i, with j remaining transactions, status is holding stack
            vector<vector<vector<double>>> memo(n, vector<vector<double>>(k+1, vector<double>(2, INT_MIN)));
            memo[0][0][0] = 0;
            memo[0][1][1] = -prices[0]; 
            
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < k+1; j++) {
                    memo[i][j][0] = max(memo[i-1][j][0], memo[i-1][j][1]+prices[i]);
                    if (j > 0) {
                        memo[i][j][1] = max(memo[i-1][j][1], memo[i-1][j-1][0]-prices[i]);
                    }
                }
            }
            
            double res = 0;
            for (int j = 0; j < k+1; j++) {
                res = max(res, memo[n-1][j][0]);
            }
            return (int)res;
        }
        
    }
};