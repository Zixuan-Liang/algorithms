class Solution {
public:
    
    string rotate(string num) {
        string res = "";
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] == '2' || num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '7') {
                return "";
            }
            else if (num[i] == '6') {
                res += '9';
            }
            else if (num[i] == '9') {
                res += '6';
            }
            else {
                res += num[i];
            }
        }
        return res;
    }
    
    bool isStrobogrammatic(string num) {
        return rotate(num) == num;
    }
};