class Solution {
public:
    string reformat(string s) {
        if (s.size() == 0 || s.size() == 1) return s;
        vector<char> letters, digits;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') letters.push_back(c);
            if (c >= '0' && c <= '9') digits.push_back(c);
        }
        int lLen = letters.size(), dLen = digits.size();
        if (abs(lLen - dLen) >= 2) return "";
        string res = "";
        int len = min(lLen, dLen);
        for (int i = 0; i < len; i++) {
            res += letters[i];
            res += digits[i];
        }
        if (lLen > dLen) res += letters.back();
        if (lLen < dLen) res = string(1, digits.back()) + res;
        return res;
    }
};