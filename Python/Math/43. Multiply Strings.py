class Solution:
    def multiply(self, num1, num2):
        ans = [0 for _ in range(len(num1) + len(num2))]

        for i in range(len(num1) - 1, -1, -1):
            carry = 0
            for j in range(len(num2) - 1, -1, -1):
                tmp = ans[i + j + 1] - 0 + (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0')) + carry
                ans[i + j + 1] = tmp % 10
                carry = tmp//10
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