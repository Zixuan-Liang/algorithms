// The len < 6 and 6 <= len <= 20 cases are easy. When len > 20, we need to do len - 20 times deletion. 
// Also we need to do a change for every three repeating characters.

// For any repeating sequences with len % 3 == 0, we can reduce one replacement by deleting one character. 
// For any repeating sequences with len % 3 == 1, we can reduce one replacement by deleting two character. 
// For the remaining sequences, we can reduce every replacement by deleting three character.

class Solution {
public:
    int strongPasswordChecker(string password) {
        string s = password;
        int missing_type = 3;
        bool lower = false, upper = false, number = false;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') lower = true;
            if (c >= 'A' && c <= 'Z') upper = true;
            if (c >= '0' && c <= '9') number = true;
        }
        if (lower) missing_type--;
        if (upper) missing_type--;
        if (number) missing_type--;
        int change = 0;
        int one = 0, two = 0;
        int p = 2;
        while (p < s.size()) {
            if (s[p] == s[p-1] && s[p-1] == s[p-2]) {
                int len = 2;
                while (p  < s.size() && s[p] == s[p-1]) {
                    len++;
                    p++;
                }
                change += len / 3;
                if (len % 3 == 0) {
                    one++;
                }
                else if (len % 3 == 1) {
                    two++;
                }
            }
            else {
                p++;
            }
        }
        if (s.size() < 6) {
            return max(missing_type, 6 - (int)s.size());
        }
        else if (s.size() <= 20) {
            return max(missing_type, change);
        }
        else {
            int del = s.size() - 20;
            change -= min(del, one);
            change -= min(max(del - one, 0), two * 2) / 2;
            change -= max(del - one - 2 * two, 0) / 3;
            return del + max(missing_type, change);
        }
    }
};







