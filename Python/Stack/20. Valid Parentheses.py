class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        lookup = {']':'[', ')':'(', '}':'{'}
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                if len(stack)==0 or stack[-1]!=lookup[c]: return False
                stack.pop()
        return len(stack)==0