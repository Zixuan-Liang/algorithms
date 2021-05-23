# Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
#
# You may assume the integer do not contain any leading zero, except the number 0 itself.
#
# The digits are stored such that the most significant digit is at the head of the list.

def plus_one(digits):
    length = len(digits)
    if length == 0:
        return [1]
    ans = []
    carry = 0
    for i in range(length - 1, -1, -1):
        if i == length - 1:
            temp = digits[i] + 1 + carry
            ans.append(temp % 10)
            carry = temp / 10
        else:
            temp = digits[i] + carry
            ans.append(temp % 10)
            carry = temp / 10
    if carry == 1:
        ans.append(1)
    return ans[::-1]