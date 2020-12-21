class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        left = ['(', '[', '{']
        right = [')', ']', '}']
        table = dict(zip(right, left))
        for char in s:
            if char in left:
                stack.append(char)
            else:
                if len(stack) == 0:
                    return False
                elif stack[-1] != table[char]:
                    return False
                else:
                    stack.pop()
        return len(stack)==0