class Solution {
public:
    
    bool helper(string& s1, int i1, string& s2, int i2, string& s3, int i3, map<pair<int, int>, bool>& memo) {
        if (memo.find({i1, i2}) == memo.end()) {
            bool res;
            if (i1 >= s1.size()) {
                res = s2.substr(i2) == s3.substr(i3);
            }
            else if (i2 >= s2.size()) {
                res = s1.substr(i1) == s3.substr(i3);
            }
            else if (s1[i1] != s3[i3] && s2[i2] != s3[i3]) {
                res = false;
            }
            else {
                res = (s1[i1]==s3[i3] && helper(s1, i1+1, s2, i2, s3, i3+1, memo)) || (s2[i2]==s3[i3] && helper(s1, i1, s2, i2+1, s3, i3+1, memo));
            }
            memo[{i1, i2}] = res;
        }
        return memo[{i1, i2}];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        map<pair<int, int>, bool> memo;
        return helper(s1, 0, s2, 0, s3, 0, memo);
    }
};