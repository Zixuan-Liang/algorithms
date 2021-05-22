class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        if (len == 0) return 0;
        if (len > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - len; i++) {
            if (haystack.substr(i, len) == needle)
                return i;
        }
        return -1;
    }
};