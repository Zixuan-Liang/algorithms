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
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
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
        if (patterns.find(endWord) == patterns.end()) return res;
        // beginWord不在字典里
        if (patterns.find(beginWord) == patterns.end()) {
            patterns[beginWord] = pattern(beginWord);
        }
        // 构造目标匹配
        unordered_set<string> target;
        for (string& p : patterns[endWord]) target.insert(p);
        // 广度优先搜索
        queue<vector<string>> que;
        que.push({beginWord});
        unordered_set<string> visited;
        vector<string> vec = {beginWord};
        bool found = false;
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                vector<string> front = que.front();
                visited.insert(front.back());
                for (string& p : patterns[front.back()]) {
                    if (target.find(p) != target.end()) {
                        found = true;
                        front.push_back(endWord);
                        res.push_back(front);
                        front.pop_back();
                    }
                    else {
                        for (string& n : neighbors[p]) {
                            if (visited.find(n) == visited.end()) {
                                front.push_back(n);
                                que.push(front);
                                front.pop_back();
                            }
                        }
                    }
                }
                que.pop();
            }
            if (found) break;
        }
        return res;
    }
};