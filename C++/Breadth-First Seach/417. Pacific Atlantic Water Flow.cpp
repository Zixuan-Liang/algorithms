class Solution {
    
    int m;
    int n;
    vector<vector<int>> adj = {{1, 0},{-1, 0},{0, 1},{0, -1}};
    
public:
    
    set<vector<int>> search(queue<vector<int>>& q, vector<vector<int>>& heights) {
        set<vector<int>> res;
        while (!q.empty()) {
            auto front = q.front(); q.pop();
            res.insert(front);
            int r = front[0], c = front[1];
            for (auto a : adj) {
                int nr = r + a[0], nc = c + a[1];
                if (nr >= 0 && nr < m && nc >=0 && nc < n && res.find({nr, nc}) == res.end() && heights[nr][nc] >= heights[r][c]) {
                   q.push({nr, nc}) ;
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        
        queue<vector<int>> pacific, atlantic;
        for (int i = 0; i < m; i++) {
            pacific.push({i, 0});
            atlantic.push({i, n - 1});
        }
        for (int i = 0; i < n; i++) {
            pacific.push({0, i});
            atlantic.push({m - 1, i});
        }
        
        set<vector<int>> pCells = search(pacific, heights);
        set<vector<int>> aCells = search(atlantic, heights);
        
        vector<vector<int>> res;
        for (auto cell : pCells) {
            if (aCells.find(cell) != aCells.end())
                res.push_back(cell);
        }
        return res;
    }
};