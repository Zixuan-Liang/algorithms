# time O(n)
# space O(n)

class Solution:

    def calculate(self, s):
        res = 0
        stack = []
        operand = 0
        sign = 1
        for ch in s:
            if ch.isdigit():
                operand = 10*operand + int(ch)
            elif ch in ['+', '-']:
                res += sign * operand
                sign = 1 if ch == '+' else -1
                operand = 0
            elif ch == '(':
                stack.append(res)
                stack.append(sign)
                res = 0
                sign = 1
            elif ch == ')':
                res += sign * operand
                res *= stack.pop()
                res += stack.pop()
                operand = 0
        return res + sign * operand
