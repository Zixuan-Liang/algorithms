class Solution {
public:
    
    int numDecodings(string s) {
        int m1 = 1, m2 = s[0]=='0' ? 0 : 1;
        if (s.size() == 1) return m2;
        for (int i = 1; i < s.size(); i++) {
            int temp = m2;
            string subs = s.substr(i-1, 2);
            m2 = m1 * ((subs >= "10" && subs <= "26") ? 1 : 0) + m2 * (s[i] == '0' ? 0 : 1);
            m1 = temp;
        }
        return m2;
    }
};