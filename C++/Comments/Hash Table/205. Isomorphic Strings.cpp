class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); i++) {
            if (!s2t.count(s[i]) && !t2s.count(t[i])) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            else if (s2t.count(s[i]) && s2t[s[i]] != t[i] || t2s.count(t[i]) && t2s[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};