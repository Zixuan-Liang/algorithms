struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    string data;
    int rank;
    TrieNode(): isEnd(false), data(""), rank(0) {}
};

class AutocompleteSystem {
    
    TrieNode* root;
    string keyword;
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        keyword = "";
        for (int i = 0; i < sentences.size(); i++) {
            addRecord(sentences[i], times[i]);
        }
    }
    
    void addRecord(string sentence, int hot) {
        TrieNode* p = root;
        for (char c : sentence) {
            if (p->children.find(c) == p->children.end()) {
                p->children[c] = new TrieNode();
            }
            p = p->children[c];
        }
        p->isEnd = true;
        p->data = sentence;
        p->rank -= hot;
    }
    
    vector<pair<int, string>> dfs(TrieNode* root) {
        vector<pair<int, string>> res;
        if (root) {
            if (root->isEnd) {
                res.push_back({root->rank, root->data});
            }
            for (auto& item : root->children) {
                vector<pair<int, string>> childRes = dfs(item.second);
                res.insert(res.end(), childRes.begin(), childRes.end());
            }
        }
        return res;
    }
    
    vector<pair<int, string>> search(string sentence) {
        TrieNode* p = root;
        for (char c : sentence) {
            if (p->children.find(c) == p->children.end()) {
                return {};
            }
            p = p->children[c];
        }
        return dfs(p);
    }
    
    vector<string> input(char c) {
        vector<pair<int, string>> res;
        if (c != '#') {
            keyword += c;
            res = search(keyword);
        }
        else {
            addRecord(keyword, 1);
            keyword = "";
        }
        sort(res.begin(), res.end());
        vector<string> ans;
        for (int i = 0; i < res.size() && i < 3; i++) {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */