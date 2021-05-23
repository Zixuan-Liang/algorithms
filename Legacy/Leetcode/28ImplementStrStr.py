# Implement strStr().
#
# Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

def strStr(haystack, needle):
    """
    :type haystack: str
    :type needle: str
    :rtype: int
    """
    if (needle == ""):
        return 0
    index = 0
    start = 0
    while (start <= len(haystack) - len(needle)):
        if (haystack[start + index] != needle[index]):
            start += 1
            index = 0
        elif (index == len(needle) - 1):
            return start
        else:
            index += 1
    return -1