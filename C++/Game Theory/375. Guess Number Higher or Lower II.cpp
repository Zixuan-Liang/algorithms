class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minRes = INT_MAX;
                for (int pivot = start; pivot < start + len - 1; pivot++) {
                    int res = pivot + max(dp[start][pivot-1], dp[pivot+1][start+len-1]);
                    minRes = min(res, minRes);
                }
                dp[start][start+len-1] = minRes;
            }
        }
        return dp[1][n];
    }
};