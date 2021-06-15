class Solution {
public:
    
    string alienOrder(vector<string>& words) {
        
        // Construct graph
        vector<int> v(26, 0);
        for (string w : words)
            for (char c : w)
                v[c - 'a'] = 1;
        
        unordered_map<char, unordered_set<char>> umap;
        unordered_map<char, int> degree;
        for (int i = 0; i < 26; i++) {
            if (v[i] == 1) {
                char c = 'a' + i;
                umap[c] = unordered_set<char>();
                degree[c] = 0;
            }
        }
        
        string prev = "";
        for (string w : words) {
            int i = 0;
            bool flag = false;
            while (i < prev.size() && i < w.size()) {
                if (prev[i] != w[i]) {
                    if (!umap[prev[i]].count(w[i])) {
                        umap[prev[i]].insert(w[i]);
                        degree[w[i]]++;
                    }
                    flag = true;
                    break;
                }
                i++;
            }
            if (!flag && i < prev.size()) {
                return "";
            }
            prev = w;
        }
        
        // BFS
        queue<char> q;
        unordered_set<char> used;
        for (auto d : degree) {
            if (d.second == 0) {
                q.push(d.first);
                used.insert(d.first);
            }
        }
        
        string res = "";
        while (!q.empty()) {
            char front = q.front(); q.pop();
            res += front;
            for (char c : umap[front]) {
                degree[c]--;
                if (degree[c] == 0 && !used.count(c)) {
                    q.push(c);
                }
            }
        }
        
        // If some characters are not used, there is a circle
        if (res.size() == degree.size()) return res;
        else return "";
    }
};
