class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> umap;
        for (int s : stones)
            umap[s] = unordered_set<int>();
        umap[0].insert(0);
        for (int stone : stones) {
            for (int step : umap[stone]) {
                for (int s = step - 1; s <= step + 1; s++) {
                    if (s > 0 && umap.count(stone + s)) {
                        umap[stone + s].insert(s);
                    }
                }
            }
        }
        return umap[stones.back()].size() > 0;
    }
};