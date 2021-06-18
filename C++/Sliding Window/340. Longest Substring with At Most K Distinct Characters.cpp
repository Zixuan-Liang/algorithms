class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> counts;
        int i = 0, j = 0;
        int res = 0;
        while (j < s.size()) {
            while (j < s.size() && counts.size() <= k) {
                counts[s[j]]++;
                if (counts.size() <= k) {
                    res = max(res, j - i + 1);
                    j++;
                }
                else {
                    break;
                }
            }
            while (i+1 < s.size() && counts.size() > k) {
                counts[s[i]]--;
                if (counts[s[i]] == 0) counts.erase(s[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};