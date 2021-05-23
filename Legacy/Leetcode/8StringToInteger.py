# Implement atoi to convert a string to an integer.

import sys
def myAtoi(s):
    sign, base, i = 1, 0, 0
    if s == '' or s == ' ':
        return 0
    while s[i] == ' ':
        i += 1
    if s[i] == '-' or s[i] == '+':
        sign = 1 - 2 * (s[i] == '-')
        i += 1
    while i < len(s) and s[i] >= '0' and s[i] <= '9':
        if base > 214748364 or base == 214748364 and int(s[i]) - 0 > 7:
            if sign == 1:
                return 2147483647
            else:
                return -2147483648
        base = 10 * base + (int(s[i]) - 0)
        i += 1
    return base * sign