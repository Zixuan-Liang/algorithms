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
    
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> v = split(text);
        int cant = 0;
        unordered_set<char> uset(begin(brokenLetters), end(brokenLetters));
        for (string s : v) {
            for (char c : s) {
                if (uset.count(c)) {
                    cant++;
                    break;
                }
            }
        }
        return v.size() - cant;
    }
};