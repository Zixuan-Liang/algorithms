#include <unordered_map>

// 字典树
// 节点定义：子节点哈希表、是否单词的标志
// 基础字典树208
class Trie {
    
public:
    
    unordered_map<char, Trie*> children;
    bool isWord = false;
    string data; // 单词最后一个字母的节点保存整个单词，以方便返回数据
    
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
        node->data = word;
    }

};

class Solution {
    
    int m;
    int n;
    vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
    
public:
    
    void backtrack(vector<vector<char>>& board, Trie* node, int i, int j, unordered_set<string>& ans) {
        char letter = board[i][j];
        if (node->children.count(letter)) { // 当前节点的子节点包含当前字符才继续进行
            node = node->children[letter]; // 指向当前字符的节点
            if (node->isWord) { // 找到一个单词
                ans.insert(node->data);
            }
            board[i][j] = '#'; // 当前字符改为#，标记为已访问
            for (auto [di, dj] : adjs) { // 对邻居进行回溯搜索
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    backtrack(board, node, ni, nj, ans);
                }
            }
            board[i][j] = letter; // 恢复原来字符
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 用所有单词建立字典树
        Trie* trie = new Trie();
        for (string word : words) {
            trie->insert(word);
        }
        // 回溯法查找单词
        m = board.size();
        n = board[0].size();
        unordered_set<string> ans; // 用哈希集合来保存ans是因为可能有重复单词
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtrack(board, trie, i, j, ans);
            }
        }
        return vector<string>(ans.begin(), ans.end()); // 把集合转换成数组返回
    }
};





