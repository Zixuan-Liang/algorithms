struct Trie {
    unordered_map<string, Trie*> next;
    string data = "";
};

class FileSystem {
    
    Trie* trie;
    
public:
    FileSystem() {
        trie = new Trie();
    }
    
    vector<string> split(string& s, string del = " ") {
        vector<string> res;
        int start = 0;
        int end = s.find(del);
        while (end != -1) {
            res.push_back(s.substr(start, end - start));
            start = end + del.size();
            end = s.find(del, start);
        }
        res.push_back(s.substr(start, end - start));
        return res;
    }
    
    Trie* find(string path) {
        Trie* node = trie;
        if (path.size() == 1) {
            return trie;
        }
        vector<string> pathSplit = split(path, "/");
        for (int i = 1; i < pathSplit.size(); i++) {
            string word = pathSplit[i];
            if (!node->next.count(word)) {
                node->next[word] = new Trie();
            }
            node = node->next[word];
        }
        return node;
    }
    
    vector<string> ls(string path) {
        Trie* node = find(path);
        if (node->data != "") {
            return {split(path, "/").back()};
        }
        else {
            vector<string> res;
            for (auto [key, value] : node->next) {
                res.push_back(key);
            }
            sort(res.begin(), res.end());
            return res;
        }
    }
    
    void mkdir(string path) {
        find(path);
    }
    
    void addContentToFile(string filePath, string content) {
        Trie* node = find(filePath);
        node->data += content;
    }
    
    string readContentFromFile(string filePath) {
        Trie* node = find(filePath);
        return node->data;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */