class Solution:
    def myAtoi(self, s: str) -> int:
        CAP, INT_MAX, INT_MIN = 214748364, 2147483647, -2147483648
        if len(s) == 0: return 0
        i = 0
        sign = 1
        while (s[i].isspace() and i+1<len(s)): i+=1
        res = 0
        if s[i] in ['-','+']: 
            sign = 1 if s[i]=='+' else -1
            i += 1
        while i < len(s):
            if s[i].isdigit():
                if res > CAP or (res == CAP and ord(s[i])-ord('0')>=8): 
                    return INT_MAX if sign==1 else INT_MIN
                res = res * 10 + (ord(s[i])-ord('0'))
                i += 1
            else:
                return res * sign
        return res*sign