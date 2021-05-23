# A message containing letters from A-Z is being encoded to numbers using the following mapping:
#
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# Given an encoded message containing digits, determine the total number of ways to decode it.
#
# For example,
# Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
#
# The number of ways decoding "12" is 2.

def num_decodings(s):
    length = len(s)
    if length == 0:
        return 0
    if length == 1:
        return (s != '0') * 1
    table = [0 for _ in range(length)]
    for i in range(length):
        if i == 0:
            table[i] = (s[-1] != '0')
        elif i == 1:
            table[i] = (s[-1] != '0') * (s[-2] != '0') + (s[-2:] >= '10' and s[-2:] <= '26')
        else:
            table[i] = (s[-(i + 1)] != '0') * table[i - 1] + \
                       table[i - 2] * (s[-(i + 1):-(i - 1)] >= '10' and s[-(i + 1):-(i - 1)] <= '26')
    return table[-1]