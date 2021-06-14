class Solution {
public:
    
    void backtrack(vector<set<char>>& options, vector<int>& idx, string temp, vector<string>& res, int i) {
        if (i == idx.size()) {
            res.push_back(temp);
        }
        else {
            auto chars = options[i];
            for (char c : chars) {
                temp[idx[i]] = c;
                backtrack(options, idx, temp, res, i+1);
            }
        }
    }
    
    vector<string> expand(string s) {
        string temp = "";
        vector<set<char>> options;
        vector<int> idx;
        int index = 0;
        while(index < s.size()) {
            if (s[index] != '{') {
                temp += s[index];
            }
            else {
                temp += '?';
                idx.push_back(temp.size()-1);
                set<char> chars;
                while (index < s.size() && s[index] != '}') {
                    if (s[index] >= 'a' && s[index] <= 'z') {
                        chars.insert(s[index]);
                    }
                    index++;
                }
                options.push_back(chars);
            }
            index++;
        }
        
        vector<string> res;
        backtrack(options, idx, temp, res, 0);
        return res;
    }
};