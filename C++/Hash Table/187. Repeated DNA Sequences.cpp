class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        
        unordered_map<string, int> umap;
        for (int i = 0; i <= s.size() - 10; i++) {
            string subs = s.substr(i, 10);
            umap[subs]++;
        }
        
        vector<string> res;
        for (auto& item : umap) {
            if (item.second > 1)
                res.push_back(item.first);
        }
        return res;
    }
};