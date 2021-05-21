class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -2147483648
        CAP = 214748364
        if x == INT_MIN: return 0
        sign = 1 if x >= 0 else -1
        x = abs(x)
        res = 0
        while x:
            digit = x%10
            if res > CAP: return 0
            if res == CAP and ((sign==1 and digit>=8) or (sign==-1 and digit==9)): return 0
            res = res * 10 + digit
            x //= 10
        return res * sign