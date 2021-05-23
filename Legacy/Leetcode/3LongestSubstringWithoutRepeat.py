# Given a string, find the length of the longest substring without repeating characters.
#
# Examples:
#
# Given "abcabcbb", the answer is "abc", which the length is 3.
#
# Given "bbbbb", the answer is "b", with the length of 1.
#
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#

def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    """
    start = maxLen = 0
    usedChr = {}

    for i in range(len(s)):
        if s[i] in usedChr and start <= usedChr[s[i]]:
            start = usedChr[s[i]] + 1
        else:
            maxLen = max(maxLen, i - start + 1)

        usedChr[s[i]] = i

    return maxLen