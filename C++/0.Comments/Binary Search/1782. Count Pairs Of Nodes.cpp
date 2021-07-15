struct PairHash{
    std::size_t operator()(const pair<int, int>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1^h2;
    }
};

class Solution {
public:

    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n, 0);
        unordered_map<pair<int,int>, int, PairHash> sharedEdges;
        // O(E)
        for (auto& edge : edges) {
            degree[edge[0]-1]++;
            degree[edge[1]-1]++;
            sharedEdges[{min(edge[0],edge[1]), max(edge[0],edge[1])}]++;
        }
        
        // O(nlogn)
        vector<int> degreeSorted = degree;
        sort(degreeSorted.begin(), degreeSorted.end());
        
        vector<int> ans;
        
        // O(Qnlogn + Qlogn + QE)
        for (int query : queries) {
            int pairs = 0;
            for (int i = 0; i < n; i++) {
                auto ub = upper_bound(degreeSorted.begin(), degreeSorted.end(), query - degreeSorted[i]);
                pairs += (degreeSorted.end() - ub);
            }
            auto ub = upper_bound(degreeSorted.begin(), degreeSorted.end(), query/2);
            pairs -= (degreeSorted.end() - ub);
            pairs /= 2;
            for (auto [edge, count] : sharedEdges) {
                int tmp = degree[edge.first-1] + degree[edge.second-1];
                if (tmp > query && tmp - count <= query) {
                    pairs--;
                }
            }
            ans.push_back(pairs);
        }
        
        return ans;
    }
    
};



