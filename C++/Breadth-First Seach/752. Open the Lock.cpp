class Solution {
    
public:
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> stop;
        for (string& s : deadends) stop.insert(s);
        
        unordered_set<string> visited;
        queue<string> q;
        if (stop.count("0000")) return -1;
        q.push("0000");
        visited.insert("0000");
        
        int turns = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int _ = 0; _ < len; _++) {
                string curr = q.front();
                cout << curr << endl;
                q.pop();
                if (curr == target) return turns;
                for (int i = 0; i < 4; i++) {
                    string next = curr;
                    char c = curr[i];
                    if (c <= '8') next[i] = c + 1;
                    else next[i] = '0';
                    if (!stop.count(next) && !visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                    if (c >= '1') next[i] = c - 1;
                    else next[i] = '9';
                    if (!stop.count(next) && !visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};