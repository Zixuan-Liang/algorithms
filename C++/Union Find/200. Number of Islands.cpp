class DSU {
public:
    
    int m, n, size;
    vector<int> parent, rank;
    
    DSU(vector<vector<char>>& grid) {
        size = 0;
        m = grid.size(); 
        n = grid[0].size();
        rank.resize(m * n, 0);
        parent.resize(m * n, -1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = idx(i, j);
                if (grid[i][j] == '1') {
                    size++;
                    parent[k] = k;
                }
            }
        }
    }
    
    int idx(int i, int j) {
        return i * n + j;
    }
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        else {
            return find(parent[x]);
        }
    }
    
    bool uni(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset != yset) {
            if (rank[xset] < rank[yset]) {
                parent[xset] = parent[yset];
            }
            else if (rank[yset] < rank[xset]){
                parent[yset] = parent[xset];
            }
            else {
                parent[yset] = parent[xset];
                rank[xset]++;
            }
            size--;
            return true;
        }
        else {
            return false;
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        DSU dsu(grid);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    if (j > 0 && grid[i][j-1] == '1') {
                        dsu.uni(dsu.idx(i, j), dsu.idx(i, j-1));
                    }
                    if (i > 0 && grid[i-1][j] == '1') {
                        dsu.uni(dsu.idx(i, j), dsu.idx(i-1, j));
                    }
                }
            }
        }
        return dsu.size;
    }
};








