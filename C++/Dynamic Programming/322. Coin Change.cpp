class Solution {
public:
    
    unordered_map<int, int> dp;
    int minCoin;
    
    int helper(vector<int>& coins, int amount) {
        if (dp.count(amount)) {
            return dp[amount];
        }
        if (amount == 0) {
            return 0;
        }
        if (amount < minCoin) {
            return -1;
        }
        int ans = INT_MAX;
        for (int coin : coins) {
            int candidate = helper(coins, amount - coin);
            if (candidate != -1) {
                ans = min(ans, candidate);
            }
        }
        if (ans == INT_MAX) {
            dp[amount] = -1;
            return -1;
        }
        else {
            dp[amount] = ans + 1;
            return ans + 1;
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        minCoin = *min_element(coins.begin(), coins.end());
        return helper(coins, amount);
    }
};