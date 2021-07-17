class Solution {
    
    unordered_map<int, unordered_set<int>> graph;
    vector<int> count;
    int n;
        
public:
    
    void dfs(int node, int parent, vector<int>& res) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node, res);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }
    
    void dfs2(int node, int parent, vector<int>& res) {
        for (int child : graph[node]) {
            if (child != parent) {
                res[child] = res[node] - count[child] + n - count[child];
                dfs2(child, node, res);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph.clear();
        for (auto& e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        count = vector<int>(n, 1);
        vector<int> res(n, 0);
        dfs(0, -1, res);
        dfs2(0, -1, res);
        return res;
    }
};