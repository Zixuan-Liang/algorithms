class Solution {
public:
    
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
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> stk;
        vector<int> ans(n, 0);
        int time = 0;
        for (string& log : logs) {
            vector<string> s = split(log, ":");
            int id = stoi(s[0]);
            string fn = s[1];
            int timestamp = stoi(s[2]);
            if (fn == "start") {
                if (!stk.empty()) ans[stk.top()] += timestamp - time;
                stk.push(id);
                time = timestamp;
            }
            else {
                ans[stk.top()] += timestamp - time + 1;
                stk.pop();
                time = timestamp + 1;
            }
        }
        return ans;
    }
};