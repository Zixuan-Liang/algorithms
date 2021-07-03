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
            if (c == secret[i]) {
                bull++;
                if (--umap[c] == 0) umap.erase(c);
            }
        }
        for (int i = 0; i < guess.size(); i++) {
            char c = guess[i];
            if (c != secret[i] && umap.count(c)) {
                cow++;
                if (--umap[c] == 0) umap.erase(c);
            }
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        
        map<char, int> present;
        int b = 0, c = 0;
        for(int i=0; i<n; i++){
            if(secret[i] == guess[i])
                b++;
            else
                present[secret[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(guess[i] != secret[i]){
                if(present[guess[i]] > 0){
                    c++;
                    present[guess[i]]--;
                }
            }
        }
        return to_string(b) + "A" + to_string(c) + "B";
    }
};