class Solution {
private:
    bool isValid(string num) {
        int size = num.size();
        if (size == 1) return true;
        if (size == 2 && num[0] >= '1') return true;
        if (size == 3 &&
            (num[0] == '1' ||
             num[0] == '2' && (num[1] < '5' || num[1] == '5' && num[2] <= '5')))
            return true;
        return false;
    }
    void backtrack(vector<string>& ans, vector<string>& cur, string& s, int index) {
        if (cur.size() > 4) {
            return;
        }
        else if (index == s.size() && cur.size() == 4) {
            string ip = cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3];
            ans.push_back(ip);
            return;
        }
        else {
            for (int len = 1; len <= 3; len++) {
                string num = s.substr(index, len);
                if (num.size() < len) break;
                if (isValid(num)) {
                    cur.push_back(num);
                    backtrack(ans, cur, s, index + len);
                    cur.pop_back();
                }
            }
        }
        
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return {};
        vector<string> ans, cur;
        backtrack(ans, cur, s, 0);
        return ans;
    }
};