class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        strList = ["" for _ in range(numRows)]
        r = numRows * 2 - 2
        for i, c in enumerate(s):
            idx = i%r
            idx = idx if idx<numRows else 2*(numRows-1)-idx
            strList[idx] += c
        return ''.join(strList)