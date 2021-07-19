class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res = "";
        int left = 0, right = 0;
        while (right < s.size()) {
            while (right < s.size() && s[left] == s[right]) {
                right++;
            }
            res += to_string(right - left) + s[left];
            left = right;
        }
        return res;
    }
};