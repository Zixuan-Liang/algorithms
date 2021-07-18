class Solution {
public:
    string sortString(string s) {
        vector<int> alphabet(26, 0);
        for (char c : s) {
            alphabet[c - 'a']++;
        }
        string ans = "";
        bool inc = false;
        while (ans.size() < s.size()) {
            inc = !inc;
            for (int i = 0; i < 26; i++) {
                int index = inc ? i : 25 - i;
                if (alphabet[index] > 0) {
                    ans += ('a' + index);
                    alphabet[index]--;
                }
            }
        }
        return ans;
    }
};