class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> umap;
        for (int t : time) {
            int remainder = t % 60;
            umap[remainder]++;
        }
        int ans = 0;
        for (auto [remainder, count] : umap) {
            if (remainder == 0 || remainder == 30) {
                ans += count * (count - 1);
            }
            else if (umap.count(60 - remainder)) {
                ans += umap[remainder] * umap[60 - remainder];
            }
        }
        return ans / 2;
    }
};