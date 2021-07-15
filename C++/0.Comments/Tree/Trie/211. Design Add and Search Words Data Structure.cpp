#include <unordered_map>

// 字典树
// 节点定义：子节点哈希表、是否单词的标志
// 基础字典树208
class Trie {
    
    unordered_map<char, Trie*> children;
    bool isWord = false;
    
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) { // 插入单词
        Trie* node = this;
        for (char c : word) { // 遍历单词的每个字母
            if (!node->children.count(c)) { // 如果字母不在子节点哈希表里，开辟一个新节点
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isWord = true; // 最后一个字母节点的是否单词标志设为真
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) { // 搜索单词
        Trie* node = this;
        for (int i = 0; i < word.size(); i++) { // 遍历单词的每个字母
            char c = word[i];
            if (c == '.') { // 匹配外卡字符'.'
                for (auto [key, child] : node->children) { // 递归搜索子节点
                    if (child->search(word.substr(i+1))) return true;
                }
                return false;
            }
            else if (!node->children.count(c)) { // 如果字母不在子节点哈希表里，直接返回，单词不存在
                return false;
            }
            node = node->children[c];
        }
        return node->isWord; // 最后一个字母节点的单词标志应该为真
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