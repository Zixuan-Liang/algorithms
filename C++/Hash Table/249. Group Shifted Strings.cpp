class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> umap;
        for (string& s : strings) {
            int shift = s[0] - 'a';
            string key = s;
            for (int i = 0; i < s.size(); i++) {
                key[i] = (key[i] - shift >= 'a') ? key[i] - shift : key[i] + 26 - shift;
            }
            umap[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto& item : umap) {
            res.push_back(item.second);
        }
        return res;
    }
};