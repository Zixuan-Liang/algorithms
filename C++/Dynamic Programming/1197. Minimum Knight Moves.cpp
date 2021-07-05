struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        auto intHash = hash<int>();
        return intHash(p.first) ^ intHash(p.second);
    }  
};

class Solution {
    
    typedef unordered_map<pair<int,int>, int, PairHash> umap;
    
public:
    
    int helper(int x, int y, umap& dp) {
        x = abs(x);
        y = abs(y);
        if (dp.count({x, y})) {
            return dp[{x, y}];
        }
        else if (x == 0 && y == 0) {
            return 0;
        }
        else if (x + y == 2) {
            return 2;
        }
        else {
            int ans = 1 + min(helper(x-1, y-2, dp), helper(x-2, y-1, dp));
            dp[{x, y}] = ans;
            return ans;
        }
    }
    
    int minKnightMoves(int x, int y) {
        umap dp;
        return helper(x, y, dp);
    }
};