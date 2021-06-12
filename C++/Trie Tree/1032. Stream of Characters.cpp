struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode(): isEnd(false) {}
};

class StreamChecker {
    
    TrieNode* root = new TrieNode();
    deque<char> stream;
    
public:
    
    StreamChecker(vector<string>& words) {
        for (string& w : words) {
            TrieNode* node = root;
            reverse(w.begin(), w.end());
            for (char c : w) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        TrieNode* node = root;
        for (char c : stream) {
            if (node->isEnd) {
                return true;
            }
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */