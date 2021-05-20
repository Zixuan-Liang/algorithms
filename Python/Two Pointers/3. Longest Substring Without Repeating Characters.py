class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        memo = {}
        res = 0
        start = 0
        for i, c in enumerate(s):
            if c in memo and memo[c]>=start:
                start = memo[c] + 1
            else:
                res = max(res, i-start+1)
            memo[c] = i
        return res