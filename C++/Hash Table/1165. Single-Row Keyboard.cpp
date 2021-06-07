class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> umap;
        for (int i = 0; i < keyboard.size(); i++) umap[keyboard[i]] = i;
        int curr = 0;
        int res = 0;
        for (char c : word) {
            res += abs(umap[c] - curr);
            curr = umap[c];
        }
        return res;
    }
};