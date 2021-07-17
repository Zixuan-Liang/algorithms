// For any qualified word, there must be at least 3 indexes (at least 1 besides 0 and n-1 which n is the length of the word), which can be used to split the whole string to at least two sub strings and all sub strings can be found in words.
// E.g. input ["cat","cats", "dog", "sdog","dogcatsdog"], for word dogcatsdog, there are 2 sets of numbers: [0, 3, 6, 10] and [0, 3, 7, 10] which can be formed by concatenating [dog, cat, sdog] and [dog, cats, dog] respectively.
// So, we can use a vector<int> dp(n+1) to store if w.substr(0, i) can be formed by existing words. Once i reach to n and it is not the word itself, we put the word to results.

class Solution {
public:

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            int n = w.size();
            vector<int> dp(n+1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) continue;
                for (int j = i+1; j <= n; j++) {
                    if (j - i < n && s.count(w.substr(i, j-i))) dp[j] = 1;
                }
                if (dp[n]) { res.push_back(w); break; }
            }
        }
        return res;
    }
    
};