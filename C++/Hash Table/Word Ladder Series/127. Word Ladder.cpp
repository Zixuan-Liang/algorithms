#include <unordered_map>
#include <queue>
#include <unordered_set>

class Solution {
public:
    
    vector<string> pattern(string& word) {
        string s = word;
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {
            char temp = s[i];
            s[i] = '*';
            res.push_back(s);
            s[i] = temp;
        }
        return res;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 构造邻接字典
        unordered_map<string, vector<string>> neighbors;
        unordered_map<string, vector<string>> patterns;
        for (string& w : wordList) {
            patterns[w] = pattern(w);
            for (string& p : patterns[w]) {
                neighbors[p].push_back(w);
            }
        }
        // endword不在字典里
        if (patterns.find(endWord) == patterns.end()) return 0;
        // beginWord不在字典里
        if (patterns.find(beginWord) == patterns.end()) {
            patterns[beginWord] = pattern(beginWord);
        }
        // 构造目标匹配
        unordered_set<string> target;
        for (string& p : patterns[endWord]) target.insert(p);
        // 广度优先搜索
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int level = 1;
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                string front = que.front();
                for (string& p : patterns[front]) {
                    if (target.find(p) != target.end()) {
                        return level+1;
                    }
                    else {
                        for (string& n : neighbors[p]) {
                            if (visited.find(n) == visited.end()) {
                                que.push(n);
                                visited.insert(n);
                            }
                        }
                    }
                }
                que.pop();
            }
            level++;
        }
        return 0;
    }
};