class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        int1 = 0
        for c in num1:
            int1 = int1 * 10 + ord(c) - ord('0')
        int2 = 0
        for c in num2:
            int2 = int2 * 10 + ord(c) - ord('0')
        
        return str(int1 + int2)