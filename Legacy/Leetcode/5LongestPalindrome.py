# Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
def expand_around_center(s, left, right):
    L, R = left, right
    while L >=0 and R < len(s) and s[L] == s[R]:
        L -= 1
        R += 1
    return R - L - 1

def longest_palindrome(s):
    start, end = 0, 0
    for i in range(len(s)):
        len1 = expand_around_center(s, i, i)
        len2 = expand_around_center(s, i, i+1)
        length = max(len1, len2)
        if length > end - start:
            start = i - (length - 1)/2
            end = i + length/2
    return s[start:end+1]

print longest_palindrome("babad")
print longest_palindrome("cbbd")