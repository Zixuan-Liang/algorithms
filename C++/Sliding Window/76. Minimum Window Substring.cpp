class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount;
        for (char c : t) charCount[c]++;
        int required = charCount.size();
        int left = 0, right = 0;
        int formed = 0;
        unordered_map<char, int> windowCount;
        int winLen = INT_MAX, start;
        
        while (right < s.size()) {
            char c = s[right];
            windowCount[c]++;
            if (charCount.find(c) != charCount.end() && windowCount[c] == charCount[c]) formed++;
            while (left <= right && formed == required) {
                c = s[left];
                if (right - left + 1 < winLen) {
                    winLen = right - left + 1;
                    start = left;
                }
                windowCount[c]--;
                if (charCount.find(c) != charCount.end() && windowCount[c] < charCount[c]) formed--;
                left++;
            }
            right++;
        }
        
        return (winLen == INT_MAX) ? "" : s.substr(start, winLen);
    }
};