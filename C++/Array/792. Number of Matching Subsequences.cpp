class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<char, vector<string>> umap;
        for (string& w : words) {
            umap[w[0]].push_back(w.substr(1));
        }
        for (char c : s) {
            vector<string> oldBucket = umap[c];
            umap[c] = vector<string>();
            for (string& suffix : oldBucket) {
                if (suffix == "") {
                    res++;
                }
                else {
                    umap[suffix[0]].push_back(suffix.substr(1));
                }
            }
        }
        return res;
    }
};