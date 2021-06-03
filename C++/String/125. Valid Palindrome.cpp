#include <cctype>

class Solution {
public:
    
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while (start < end) {
            char startC = tolower(s[start]), endC = tolower(s[end]);
            if (startC == endC) {
                start++;
                end--;
            }
            else if (!(startC >= 'a' && startC <= 'z') && !(startC >= '0' && startC <= '9')) {
                start++;
            }
            else if (!(endC >= 'a' && endC <= 'z') && !(endC >= '0' && endC <= '9')) {
                end--;
            }
            else return false;
        }
        return true;
    }
};