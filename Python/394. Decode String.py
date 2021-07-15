class Solution:
    def decodeString(self, s: str) -> str:
        numStk = []
        strStk = []
        currStr = ''
        k = 0
        for c in s:
            if c >= '0' and c <= '9':
                k = k * 10 + (ord(c) - ord('0'))
            elif c == '[':
                numStk.append(k)
                strStk.append(currStr)
                k = 0
                currStr = ''
            elif c == ']':
                currStr = strStk.pop() + currStr * numStk.pop()
            else:
                currStr += c
        return currStr
                