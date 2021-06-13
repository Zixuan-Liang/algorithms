class Solution {
public:
    string modifyString(string s) {
        string res;
        int index = 0;
        char left, right;
        while (index < s.size()) {
            if (s[index] != '?') {
                res += s[index];
                index++;
            }
            else {
                if (index > 0) left = s[index - 1];
                else left = '#';
                int start = index;
                while (index < s.size() && s[index] == '?') {
                    index++;
                }
                int len = index - start;
                if (index < s.size()) right = s[index];
                else right = '#';
                char fill1, fill2;
                for (int i = 0; i < 26; i++) {
                    if ('a' + i != left && 'a' + i != right) {
                        fill1 = 'a' + i;
                        break;
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if ('a' + i != left && 'a' + i != right && 'a' + i != fill1) {
                        fill2 = 'a' + i;
                        break;
                    }
                }
                bool turn = true;
                for (int i = 0; i < len; i++) {
                    if (turn) {
                        res += fill1;
                    }
                    else {
                        res += fill2;
                    }
                    turn = !turn;
                }
            }
        }
        return res;
    }
};