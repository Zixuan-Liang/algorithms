class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for (char c : s) umap[c]++;
        vector<pair<char, int>> chars;
        for (auto& item : umap) {
            chars.push_back({item.first, item.second});
        }
        sort(chars.begin(), chars.end(), [](const pair<char, int>& p1, const pair<char, int>& p2)->bool {
            return p1.second > p2.second;
        });
        string res = "";
        for (auto [c, n] : chars) {
            for (int i = 0; i < n; i++) {
                res += c;
            }
        }
        return res;
    }
};