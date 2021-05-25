class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int index = 0;
        while (index < s.size()) {
            if (s[index] == ' ') {
                index++;
            }
            else {
                res = 1;
                while (index+1 < s.size() && s[index+1] != ' ') {
                    index++;
                    res++;
                }
                index++;
            }
        }
        return res;
    }
};