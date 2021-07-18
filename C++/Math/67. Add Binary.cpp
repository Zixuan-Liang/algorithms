class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int n1, n2, s;
        string res;
        for (int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0; i--, j--) {
            n1 = (i >= 0) ? a[i]-'0' : 0;
            n2 = (j >= 0) ? b[j]-'0' : 0;
            s = n1 + n2 + c;
            c = s/2;
            s = s%2;
            res = string(1, '0'+s) + res;
        }
        if (c != 0) {
            res = string(1, '0'+c) + res;
        }
        return res;
    }
};