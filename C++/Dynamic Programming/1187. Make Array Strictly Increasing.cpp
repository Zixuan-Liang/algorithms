class Solution {
    
    short dp[2001][2001] = {}, m_val = 2001;

    
public:

    short dfs(vector<int>& a1, vector<int>& a2, int i1, int i2, int prev) {
        if (i1 >= a1.size()) 
          return 0;
        i2 = upper_bound(begin(a2) + i2, end(a2), prev) - begin(a2);
        if (prev >= a1[i1] && i2 >= a2.size())
          return m_val;
        if (dp[i1][i2] == 0) {
        dp[i1][i2] = i2 < a2.size() ? 1 + dfs(a1, a2, i1 + 1, i2, a2[i2]) : m_val;
        if (prev < a1[i1])
            dp[i1][i2] = min(dp[i1][i2], dfs(a1, a2, i1 + 1, i2, a1[i1]));
        }
        return dp[i1][i2];
    }
    
    int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
        sort(begin(a2), end(a2));
        auto res = dfs(a1, a2, 0, 0, INT_MIN);
        return res >= m_val ? -1 : res;
    }
    
};