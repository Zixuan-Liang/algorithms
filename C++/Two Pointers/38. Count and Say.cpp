class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string res = "";
        int len = prev.size();
        int left = 0, right;
        while (left < len) {
            right = left;
            while (right < len && prev[left] == prev[right]) {
                right += 1;
            }
            res += to_string(right-left) + prev[left];
            left = right;
        }
        return res;
    }
};