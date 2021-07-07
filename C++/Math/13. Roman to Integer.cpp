class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        int i = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && values[s[i]] < values[s[i+1]]) {
                ans += values[s[i+1]] - values[s[i]];
                i += 2;
            }
            else {
                ans += values[s[i]];
                i++;
            }
        }
        return ans;
    }
};