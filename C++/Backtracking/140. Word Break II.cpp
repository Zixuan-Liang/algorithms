#include <unordered_set>

class Solution {
public:
    
    void backtrack(string& s, int start, int end, unordered_set<string>& dict, vector<string>& res, vector<string>& seq) {
        if (end == s.size()) {
            if (start == end) {
                string sentence = "";
                for (int i = 0; i < seq.size(); i++) {
                    if (i == 0) sentence += seq[i];
                    else sentence += " " + seq[i];
                }
                res.push_back(sentence);
            }
        }
        else {
            string sub = s.substr(start, end-start+1);
            if (dict.find(sub) != dict.end()) {
                seq.push_back(sub);
                backtrack(s, end+1, end+1, dict, res, seq);
                seq.pop_back();
            }
            backtrack(s, start, end+1, dict, res, seq);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string> res;
        
        unordered_set<char> sChar, dictChar;
        unordered_set<string> dict;
        for (char c : s) sChar.insert(c);
        for (string& w : wordDict) {
            dict.insert(w);
            for (char c : w) {
                dictChar.insert(c);
            }
        }
        if (sChar.size() > dictChar.size()) return res;
        
        vector<string> seq;
        backtrack(s, 0, 0, dict, res, seq);
        return res;
    }
};