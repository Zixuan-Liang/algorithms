class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        table = dict()
        start = 0
        ans = 0
        for i, char in enumerate(s):
            if char in table and table[char]>=start:
                start = table[char] + 1
            else:
                ans = max(ans, i-start+1)
            table[char] = i
        return ans