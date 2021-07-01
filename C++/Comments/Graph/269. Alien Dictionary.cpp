class Solution {
public:  
    
    string alienOrder(vector<string>& words) {
        // 找出哪些字母被用过
        vector<int> v(26, 0);
        for (string w : words)
            for (char c : w)
                v[c - 'a'] = 1;
        // 图，哈希表：键：字母，值：在该字母后面的字母集合
        // 入度，哈希表，键：字母，值：有多少字母在它前面
        unordered_map<char, unordered_set<char>> umap;
        unordered_map<char, int> degree;
        for (int i = 0; i < 26; i++) {
            if (v[i] == 1) {
                char c = 'a' + i;
                umap[c] = unordered_set<char>();
                degree[c] = 0;
            }
        }
        // 每个单词和前一个单词比较
        string prev = "";
        for (string w : words) {
            // 如果前一个单词比后一个单词长，而且后一个单词是前一个单词的前缀，非法！
            if (prev.size() > w.size() && prev.find(w) == 0) return "";
            int i = 0;
            while (i < prev.size() && i < w.size()) {
                if (prev[i] != w[i]) { // 找出相邻两个单词第一个不同的字母，这包含了字母表顺序信息
                    if (!umap[prev[i]].count(w[i])) { // 如果这对组合之前没出现过，添加这对组合的记录
                        umap[prev[i]].insert(w[i]);
                        degree[w[i]]++;  // 排在后面的字母的“入度”+1
                    }
                    break;
                }
                i++;
            }
            prev = w;
        }
        // 广度优先搜索建字母表
        queue<char> q;
        unordered_set<char> used;
        for (auto d : degree) {
            if (d.second == 0) { // 初始队列：把“入度”为0的字母进队，它们都可以作为首字母
                q.push(d.first);
                used.insert(d.first);
            }
        }
        string res = "";
        while (!q.empty()) { // BFS
            char front = q.front(); q.pop();
            res += front;
            for (char c : umap[front]) {
                degree[c]--; // 当前字母的下一个字母的“入度”-1，如果变为0，而且没使用过，则将其进队
                if (degree[c] == 0 && !used.count(c)) {
                    q.push(c);
                }
            }
        }
        if (res.size() == degree.size()) return res;
        else return ""; // 如果并不是所有的字母都使用过，说明存在环：有些字母的“入度”永远降不到0，它们从来没有进队
    }
    
};


