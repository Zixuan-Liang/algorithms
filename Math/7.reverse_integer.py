class Solution:
    def reverse(self, x):
        sign = 1 if x > 0 else -1
        rst = sign * int(str(abs(x))[::-1])
        return rst if -(2**31)-1 < rst < 2**31 else 0