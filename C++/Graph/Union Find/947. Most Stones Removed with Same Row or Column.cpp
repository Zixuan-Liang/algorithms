class Solution {
public:
    
    unordered_map<int, int> parents;
    unordered_map<int, int> rank;
    int size = 0;
    
    int find(int x) {
        if (!parents.count(x)) {
            parents[x] = x;
            rank[x] = 0;
            size++;
        }
        else if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void uni(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset != yset) {
            if (rank[xset] < rank[yset]) {
                parents[xset] = yset;
            }
            else if (rank[yset] < rank[xset]) {
                parents[yset] = xset;
            }
            else {
                parents[yset] = xset;
                rank[xset]++;
            }
            size--;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        for (auto& stone : stones) {
            int i = stone[0], j = stone[1];
            uni(i, ~j);
        }
        return stones.size() - size;
    }
};