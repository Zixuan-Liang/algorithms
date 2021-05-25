class Solution {
public:
    
    bool isDigits (string s) {
        if (s.size() == 0) return false;
        bool res = true;
        for (char c : s) {
            res = res && c >= '0' && c <= '9';
            if (!res) return res;
        }
        return res;
    }
    
    bool isInteger(string s) {
        if (s.size() == 0) return false;
        if (s[0] == '+' || s[0] == '-') return isDigits(s.substr(1, s.size()-1));
        else return isDigits(s);
    }
    
    bool isNoSignDecimal(string s) {
        if (s.size() == 0) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                return (isDigits(s.substr(0, i)) && (i == s.size()-1 || isDigits(s.substr(i+1, s.size()-i-1)))) || (i == 0 && isDigits(s.substr(i+1, s.size()-i-1)));
            }
        }
        return false;
    }
    
    bool isDecimal(string s) {
        if (s.size() == 0) return false;
        if (s[0] == '+' || s[0] == '-') return isNoSignDecimal(s.substr(1, s.size()-1));
        else return isNoSignDecimal(s);
    }
    
    bool isNumber(string s) {
        if (s.size() == 0) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                return (isInteger(s.substr(0, i)) || isDecimal(s.substr(0, i))) && isInteger(s.substr(i+1, s.size()-i-1));
            }
        }
        return isInteger(s) || isDecimal(s);
    }
};