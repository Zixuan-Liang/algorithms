class DSU {
    
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    
public:
    DSU(int m, int n) {
        int N = m * n + 1;
        for (int i = 0; i < N; i++) parent.push_back(i);
        rank = vector<int>(N, 0);
        size = vector<int>(N, 1);
    }
    
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    
    void Union(int x, int y) {
        int xr = Find(x), yr = Find(y);
        if (xr == yr) return ;
        if (rank[xr] < rank[yr]) swap(xr, yr);
        if (rank[xr] == rank[yr]) rank[xr]++;
        parent[yr] = xr;
        size[xr] += size[yr];
    }
    
    int Size(int x) {
        return size[Find(x)];
    }
    
    int Top() {
        return Size(size.size() - 1) - 1;
    }
};

class Solution {
    
    int m;
    int n;
    vector<vector<int>> next = {{1,0},{-1,0},{0,1},{0,-1}};
    
public:
    
    int index(int r, int c) {
        return r * n + c;
    }
    
    vector<vector<int>> neighbors(int r, int c) {
        vector<vector<int>> res;
        for (auto& ne : next) {
            int nr = r+ne[0], nc = c+ne[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                res.push_back({nr, nc});
            }
        }
        return res;
    }
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size(); n = grid[0].size();
        vector<vector<int>> A = grid;
        for (auto& h : hits) A[h[0]][h[1]] = 0;
        DSU dsu(m, n);
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (A[r][c]) {
                    int i = index(r, c);
                    if (r == 0) dsu.Union(i, m*n);
                    if (r != 0 && A[r-1][c] == 1) dsu.Union(i, index(r-1, c));
                    if (c != 0 && A[r][c-1] == 1) dsu.Union(i, index(r, c-1));
                }
            }
        }
        vector<int> res;
        reverse(hits.begin(), hits.end());
        for (auto& h : hits) {
            int r = h[0], c = h[1];
            int preRoof = dsu.Top();
            if (grid[r][c] == 0) {
                res.push_back(0);
            }
            else {
                int i = index(r, c);
                for (auto& n : neighbors(r, c)) {
                    if (A[n[0]][n[1]] == 1) {
                        dsu.Union(i, index(n[0], n[1]));
                    }
                }
                if (r == 0) {
                    dsu.Union(i, m*n);
                }
                A[r][c] = 1;
                res.push_back(max(0, dsu.Top() - preRoof - 1));
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




