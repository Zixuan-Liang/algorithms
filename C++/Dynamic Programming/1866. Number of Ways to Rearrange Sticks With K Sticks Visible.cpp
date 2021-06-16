class Solution {
    
    int dp[1001][1001];
    
public:
    
    int rearrangeSticks(int n, int k) {
        if (n == k) return 1;
        if (k == 0) return 0;
        int mod = pow(10, 9) + 7;
        if (dp[n][k] == 0) {
            dp[n][k] = (1L * rearrangeSticks(n-1, k-1) + 1L * rearrangeSticks(n-1, k) * (n-1)) % mod;
        }
        return dp[n][k];
    }
};