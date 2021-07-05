class Solution {
    
    const static int WHITE = 1;
    const static int GRAY = 2;
    const static int BLACK = 3;
    bool isPossible;
    unordered_map<int, int> color;
    unordered_map<int, vector<int>> adjs;
    
public:
    
    void dfs(int node, vector<int>& res) {
        if (!isPossible) return ;
        color[node] = GRAY;
        if (adjs.find(node) != adjs.end()) {
            for (int neighbor : adjs[node]) {
                if (color[neighbor] == WHITE) {
                    dfs(neighbor, res);
                }
                else if (color[neighbor] == GRAY) {
                    isPossible = false;
                }
            }
        }
        color[node] = BLACK;
        res.push_back(node);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        adjs.clear();
        for (auto& p : prerequisites) {
            adjs[p[1]].push_back(p[0]);
        }
        
        vector<int> res;
        isPossible = true;
        for (int i = 0; i < n; i++) color[i] = WHITE;
        for (int i = 0; i < n; i++) {
            if (color[i] == WHITE) {
                dfs(i, res);
            }
        }
        
        if (isPossible) {
            reverse(res.begin(), res.end());
            return res;
        }
        else return {};
    }
};