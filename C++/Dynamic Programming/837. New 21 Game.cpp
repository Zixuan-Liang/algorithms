class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double slideSum = 1.0, res = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = slideSum / maxPts;
            if (i < k) slideSum += dp[i]; else res += dp[i];
            if (i - maxPts >= 0) slideSum -= dp[i - maxPts];
        }
        return res;
    }
};