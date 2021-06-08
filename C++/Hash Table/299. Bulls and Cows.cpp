class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> umap;
        for (char c : secret) {
            umap[c]++;
        }
        int bull = 0, cow = 0;
        for (int i = 0; i < guess.size(); i++) {
            char c = guess[i];
            if (umap.find(c) != umap.end()) {
                if (c == secret[i]) {
                    bull++;
                    cow -= (int)umap[c]<=0;
                }
                else {
                    cow += (int)umap[c]>0;
                }
                umap[c]--;
            }
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};