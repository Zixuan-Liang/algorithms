class Solution {
public:
    
    void backtrack(string& s, vector<string>& res, vector<string>& segments, int index) {
        if (index == s.size()) {
            if (segments.size() == 4) {
                string ip = "";
                for (int i = 0; i <= 3; i++) {
                    if (segments[i].size() > 3) return;
                    int num = stoi(segments[i]);
                    if (to_string(num) != segments[i] || num > 255) return;
                    else {
                        if (i == 0) ip += segments[i];
                        else ip += "." + segments[i];
                    }
                }
                res.push_back(ip);
            }
        }
        else {
            if (segments.size() <= 3) {
                segments.push_back(string(1, s[index]));
                backtrack(s, res, segments, index+1);
                segments.pop_back();
            }
            if (!segments.empty()) {
                segments.back() += string(1, s[index]);
                backtrack(s, res, segments, index+1);
                segments.back().pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12) return res;
        vector<string> segments;
        backtrack(s, res, segments, 0);
        return res;
    }
};