class TreeAncestor {

private:
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int>& parent) : dp(n) {

        for(int i = 0; i < n; i ++)
            dp[i].push_back(parent[i]);

        for(int j = 1; ; j ++){
            bool allneg = true;
            for(int i = 0; i < n; i ++){
                int t = dp[i][j - 1] != -1 ? dp[dp[i][j - 1]][j - 1] : -1;
                dp[i].push_back(t);
                if(t != -1) allneg = false;
            }
            if(allneg) break; // 所有的节点的 2^j 的祖先都是 -1 了，就不用再计算了
        }
    }

    int getKthAncestor(int node, int k) {

        int res = node, pos = 0;
        while(k && res != -1){
            if(pos >= dp[res].size()) return -1;
            if(k & 1) res = dp[res][pos];
            k >>= 1, pos ++;
        }
        return res;
    }
    
};

// class TreeAncestor {
    
//     vector<vector<int>> par;
    
// public:

//     TreeAncestor(int n, vector<int>& parent) {
//         par = vector<vector<int>>(n, vector<int>(20));
//         for (int i = 0; i < n; i++) par[i][0] = parent[i];
//         for (int j = 1; j < 20; j++) {
//             for (int i = 0; i < n; i++) {
//                 if (par[i][j - 1] == -1) par[i][j] = -1;
//                 else par[i][j] = par[par[i][j - 1]][j - 1];
//             }
//         }
//     }
    
//     int getKthAncestor(int node, int k) {
//         for (int i = 0; i < 20; i++) {
//             if ((k >> i) & 1) {
//                 node = par[node][i];
//                 if (node == -1) return -1;
//             }
//         }
//         return node;
//     }
    
// };

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */