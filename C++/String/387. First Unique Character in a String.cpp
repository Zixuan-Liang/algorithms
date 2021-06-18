class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letters(26, -1);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (letters[c - 'a'] == -1) {
                letters[c - 'a'] = i;
            }
            else {
                letters[c - 'a'] = -2;
            }
        }
        int res = INT_MAX;
        for (int index : letters) {
            if (index >= 0) res = min(res, index);
        }
        return res == INT_MAX ? -1 : res;
    }
};