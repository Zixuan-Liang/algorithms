class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();
        for (int limit = 1; limit <= 26; limit++) {
            vector<int> count(26, 0);
            int left = 0, right = 0;
            int unique = 0, lessThanK = 0;
            while (right < n) {
                count[s[right] - 'a']++;
                if (count[s[right] - 'a'] == 1) {
                    unique++;
                    lessThanK++;
                }
                if (count[s[right] - 'a'] == k) {
                    lessThanK--;
                }
                while(unique > limit) {
                    count[s[left] - 'a']--;
                    if (count[s[left] - 'a'] == 0) {
                        unique--;
                        lessThanK--;
                    }
                    if (count[s[left] - 'a'] == k - 1) {
                        lessThanK++;
                    }
                    left++;
                }
                if (lessThanK == 0) {
                    ans = max(ans, right - left + 1);
                }
                right++;
            }
        }
        return ans;
    }
};