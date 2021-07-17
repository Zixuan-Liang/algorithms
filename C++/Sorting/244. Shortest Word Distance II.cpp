class WordDistance {
    
    unordered_map<string, vector<int>> umap;
    
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            umap[wordsDict[i]].push_back(i);
        }
        for (auto& [word, indices] : umap) {
            sort(indices.begin(), indices.end());
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> indices1 = umap[word1];
        vector<int> indices2 = umap[word2];
        int res = INT_MAX;
        for (int index : indices1) {
            auto upper = upper_bound(indices2.begin(), indices2.end(), index);
            if (upper != indices2.end()) {
                res = min(res, abs(*upper - index));
            }
            if (upper != indices2.begin()) {
                res = min(res, abs(*(--upper) - index));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */