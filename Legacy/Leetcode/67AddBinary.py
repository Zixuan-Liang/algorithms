# Given two binary strings, return their sum (also a binary string).
#
# For example,
# a = "11"
# b = "1"
# Return "100".

def add_binary(a, b):
    a = a[::-1]
    b = b[::-1]
    ans = ''
    i = 0
    carry = 0
    length_a = len(a)
    length_b = len(b)
    while i < length_a and i < length_b:
        temp = int(a[i]) + int(b[i]) + carry
        if temp == 3:
            ans += '1'
            carry = 1
        elif temp == 2:
            ans += '0'
            carry = 1
        elif temp == 1:
            ans += '1'
            carry = 0
        elif temp == 0:
            ans += '0'
            carry = 0
        i += 1
    if i < length_a:
        while i < length_a:
            temp = int(a[i]) + carry
            if temp == 3:
                ans += '1'
                carry = 1
            elif temp == 2:
                ans += '0'
                carry = 1
            elif temp == 1:
                ans += '1'
                carry = 0
            elif temp == 0:
                ans += '0'
                carry = 0
            i += 1
    if i < length_b:
        while i < length_b:
            temp = int(b[i]) + carry
            if temp == 3:
                ans += '1'
                carry = 1
            elif temp == 2:
                ans += '0'
                carry = 1
            elif temp == 1:
                ans += '1'
                carry = 0
            elif temp == 0:
                ans += '0'
                carry = 0
            i += 1
    if carry == 1:
        ans += '1'
    return ans[::-1]