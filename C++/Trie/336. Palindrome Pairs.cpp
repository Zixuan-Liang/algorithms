class Trie {  
public:
    
    unordered_map<char, Trie*> children;
    int wordEnding = -1;
    vector<int> palindromePrefixRemaining;
    vector<vector<int>> pairs;
    
    Trie() {}
    
    bool hasPalindromeRemaining(string& word, int i) {
        int p1 = i;
        int p2 = word.size() - 1;
        while (p1 < p2) {
            if (word[p1] != word[p2]) return false;
            p1++, p2--;
        }
        return true;
    }
    
    void insert(string word, int wordId) {
        Trie* node = this;
        for (int i = 0; i < word.size(); i++) {
            if (hasPalindromeRemaining(word, i)) {
                node->palindromePrefixRemaining.push_back(wordId);
            }
            char c = word[i];
            if (!node->children.count(c)) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->wordEnding = wordId;
    }
    
    void search(string word, int wordId) {
        Trie* node = this;
        for (int i = 0; i < word.size(); i++) {
            if (node->wordEnding != -1 && hasPalindromeRemaining(word, i)) {
                pairs.push_back({wordId, node->wordEnding});
            }
            char c = word[i];
            if (!node->children.count(c)) {
                node = nullptr;
                break;
            }
            node = node->children[c];
        }
        if (!node) return ;
        if (node->wordEnding != -1 && node->wordEnding != wordId) {
            pairs.push_back({wordId, node->wordEnding});
        }
        for (int other : node->palindromePrefixRemaining) {
            pairs.push_back({wordId, other});
        }
    }
    
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        for (int wordId = 0; wordId < words.size(); wordId++) {
            string word = words[wordId];
            reverse(word.begin(), word.end());
            trie->insert(word, wordId);
        }
        
        for (int wordId = 0; wordId < words.size(); wordId++) {
            string word = words[wordId];
            trie->search(word, wordId);
        }
        
        return trie->pairs;
    }
};



