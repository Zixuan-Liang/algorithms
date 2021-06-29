class DSU {
    
public:
    
    vector<int> parent, rank;
    int size;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
        size = n;
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
            if (rank[x] < rank[y]) {
                parent[xset] = yset;
            }
            else {
                parent[yset] = xset;
            }
            if (rank[xset] == rank[yset]) {
                rank[xset]++;
            }
            size--;
            return true;
        }
        return false;
    }
    
};

class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    dsu.uni(i, j);
                }
            }
        }
        return dsu.size;
    }
};




