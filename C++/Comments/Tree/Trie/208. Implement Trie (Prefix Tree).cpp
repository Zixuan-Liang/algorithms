#include <unordered_map>

// 字典树
// 节点定义：子节点哈希表、是否单词的标志
// 复杂度：单词数量n，单词长度L
// 每次插入：时间O(L)，空间O(L)
// 每次搜索：时间O(L)，空间O(1)
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
        for (char c : word) { // 遍历单词的每个字母
            if (!node->children.count(c)) { // 如果字母不在子节点哈希表里，直接返回，单词不存在
                return false;
            }
            node = node->children[c];
        }
        return node->isWord; // 最后一个字母节点的单词标志应该为真
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { // 搜索前缀
        Trie* node = this;
        for (char c : prefix) { // 遍历前缀的每个字母
            if (!node->children.count(c)) { // 如果字母不在子节点哈希表里，直接返回，前缀不存在
                return false;
            }
            node = node->children[c];
        }
        return true; // 只要遍历完整个前缀，说明该前缀存在
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */