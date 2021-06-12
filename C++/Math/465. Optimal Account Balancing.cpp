class Solution {
public:
    
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> debt;
        for (auto& t : transactions) {
            debt[t[0]] -= t[2];
            debt[t[1]] += t[2];
        }
        vector<int> amounts;
        for (auto& d : debt) {
            if (d.second != 0)
                amounts.push_back(d.second);
        }
        int n = amounts.size();
        vector<int> dp(pow(2, n), 0);
        vector<int> sums(pow(2, n), 0);
        for (int mask = 0; mask < pow(2, n); mask++) {
            int setBit = 1;
            for (int b = 0; b < n; b++) {
                if ((mask & setBit) == 0) {
                    int next = mask | setBit;
                    sums[next] = sums[mask] + amounts[b];
                    if (sums[next] == 0) dp[next] = max(dp[next], dp[mask]+1);
                    else dp[next] = max(dp[next], dp[mask]);
                }
                setBit = setBit << 1;
            }
        }
        return n - dp.back();
    }
};