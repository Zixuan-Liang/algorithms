# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#
# The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

def isValid(s):
    """
    :type s: str
    :rtype: bool
    """
    stack = []
    dict = {')': '(', ']': '[', '}': '{'}
    for chr in s:
        if chr == '(' or chr == '[' or chr == '{':
            stack.append(chr)
        elif not stack:
            return False
        elif dict[chr] != stack.pop():
            return False
    if not stack:
        return True
    else:
        return False