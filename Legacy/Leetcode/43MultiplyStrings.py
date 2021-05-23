# Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
#
# Note:
#
# The length of both num1 and num2 is < 110.
# Both num1 and num2 contains only digits 0-9.
# Both num1 and num2 does not contain any leading zero.
# You must not use any built-in BigInteger library or convert the inputs to integer directly.


def multiply(num1, num2):
    ans = [0 for _ in range(len(num1) + len(num2))]

    for i in range(len(num1) - 1, -1, -1):
        carry = 0
        for j in range(len(num2) - 1, -1, -1):
            tmp = ans[i + j + 1] - 0 + (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0')) + carry
            ans[i + j + 1] = tmp % 10
            carry = tmp/10
        ans[i] += carry

    pos = 0

    for i in range(len(ans)):
        if i == len(ans) - 1 and ans[i] == 0:
            return '0'
        if ans[i] == 0:
            pos += 1
        else:
            break
    return ''.join([str(i) for i in ans[pos:]])

print multiply('1234', '5678')