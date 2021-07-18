// Statement: If M operations, either Union or Find, are applied to N elements, 
// the total run time is O(Mlog*N), where log* is the iterated logarithm, 
// can be seen as constant.

// Iterated logarithm is achieved when we use union by rank and path compression heuristics

#include <vector>

class DSU {
public:

    vector<int> parent, rank;
    int size;

    DSU(int n) {
        size = n;
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool uni(int x, int y) {
        int xSet = find(x), ySet = find(y);
        if (xSet != ySet) {
            if (rank[xSet] < rank[ySet]) {
                parent[xSet] = ySet;
            }
            else if (rank[ySet] < rank[xSet]){
                parent[ySet] = xSet;
            }
            else {
                parent[ySet] = xSet;
                rank[xSet]++;
            }
            size--;
            return true;
        }
        else {
            return false;
        }
    }

};