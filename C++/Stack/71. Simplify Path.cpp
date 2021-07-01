class Solution {
public:
    
    vector<string> split(string s, string del = " ") {
        vector<string> ans;
        int start = 0;
        int end = s.find(del, start);
        while (end != -1) {
            ans.push_back(s.substr(start, end - start));
            start = end + del.size();
            end = s.find(del, start);
        }
        ans.push_back(s.substr(start, end - start));
        return ans;
    }
    
    string simplifyPath(string path) {
        vector<string> s = split(path, "/");
        deque<string> dq;
        for (string& dir_file : s) {
            if (dir_file == "..") {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            }
            else if (dir_file == "." or dir_file == "") {
                continue;
            }
            else {
                dq.push_back(dir_file);
            }
        }
        if (dq.empty()) return "/";  // 注意corner case：空栈直接返回"/"
        string ans = "";
        while (!dq.empty()) {
            ans += "/" + dq.front();
            dq.pop_front();
        }
        return ans;
    }
};


