class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> chars;
        for (char c : s) {
            if (c != '-') {
                if (c >= 'a' && c <= 'z') c = 'A' + (c - 'a');
                chars.push_back(c);
            }
        }
        int n = chars.size();
        int firstGroup = (n-1) % k + 1;
        string res = "";
        for (int i = 0; i < firstGroup; i++) {
            res += chars[i];
        }
        int groups = (n - firstGroup) / k;
        for (int i = 0; i < groups; i++) {
            res += '-';
            for (int j = 0; j < k; j++) {
                res += chars[firstGroup + i * k + j];
            }
        }
        return res;
    }
};