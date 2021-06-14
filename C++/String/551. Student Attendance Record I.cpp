class Solution {
public:
    bool checkRecord(string s) {
        int late = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L' && i < s.size() - 2 && s.substr(i, 3) == "LLL") {
                return false;
            }
            else if (s[i] == 'A') {
                late++;
                if (late >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
};