class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alphabet(26);
        for (int i = 0; i < size(order); i++) {
            alphabet[order[i] - 'a'] = i;
        }
        for (int i = 0; i < size(words) - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            if (w1.find(w2) != -1 && size(w1) > size(w2)) return false;
            int j = 0, k = 0;
            bool legit = true;
            while(j < size(w1) && k < size(w2)) {
                if (w1[j] != w2[k]) {
                    legit = alphabet[w1[j] - 'a'] < alphabet[w2[k] - 'a'];
                    break;
                }
                else {
                    j++;
                    k++;
                }
            }
            if (!legit) {
                return false;
            }
        }
        return true;
    }
};