class TreeAncestor {
    
    vector<vector<int>> dp;
    
public:
    TreeAncestor(int n, vector<int>& parent): dp(n){
        // dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].push_back(parent[i]);
        }
        // 动态规划：dp[i][j] = dp[dp[i][j-1]][j-1]
        // i的第2^j个父节点是i的第2^(j-1)个父节点的第2^(j-1)个父节点
        for (int j = 1; ; j++) {
            bool allneg = true;
            for (int i = 0; i < n; i++) {
                int p = dp[i][j-1] != -1 ? dp[dp[i][j-1]][j-1] : -1;
                dp[i].push_back(p);
                if (p != -1) allneg = false;
            }
            if (allneg) break;
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node, pos = 0;
        while (k && ans != -1) {
            if (pos >= dp[ans].size()) return -1;
            if (k & 1) ans = dp[ans][pos];
            k >>= 1;
            pos++;
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */