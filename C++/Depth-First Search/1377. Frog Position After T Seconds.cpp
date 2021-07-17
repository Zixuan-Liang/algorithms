class Solution {
    
    vector<vector<int>> G;
    vector<bool> seen;
    int target;
    
public:

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1) return 1.0;
        this->target = target;
        G.resize(n + 1);
        for (auto e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        seen = vector<bool>(n + 1, false);

        return dfs(1, t);
    }

    double dfs(int i, int t) { // 从节点i在t秒后跳到target的可能性
        if (i != 1 && G[i].size() == 1 || t == 0) { // 只有一个点，或者时间为0秒
            return i == target;
        }
        seen[i] = true;
        double res = 0;
        for (auto j : G[i]) {
            if (! seen[j]) {
                res += dfs(j, t - 1); // 从子节点j在t-1秒后跳到target的可能性
            }
        }
        return res / (G[i].size() - (i != 1)); // 每个子节点都是等可能的
    }
    
};

// res / (G[i].size() - (i != 1)) explain:
// As there is no parent for 1, which is the root! In calculating probability for a certain 
// move we use formula, (1/connected_nodes) and the connected_nodes are equal to 
// children + parent but in case of 1 there is no parent.