class Trie {
    
    unordered_map<char, Trie*> children;
    bool isWord = false;
    
public:
    
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (int i = 0; i < word.size(); i++) {  
            char c = word[i];
            
            // wildcard match
            if (c == '.') {
                for (auto item : node->children) {
                    node = item.second;
                    if (node->search(word.substr(i+1))) 
                        return true;
                }
                return false;
            }
            
            if (node->children.count(c))
                node = node->children[c];
            else
                return false;
        }
        return node->isWord;
    }
    
};

class WordDictionary {
    
    Trie* trie;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */