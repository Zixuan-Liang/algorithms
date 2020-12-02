# Decode 1->A, 26->Z
# How many ways to decode a string containing only integers?

class Solution:
    def oneNum(self, s: str) -> int:
        return int(int(s) != 0)
    
    def twoNums(self, s: str) -> int:
        return int(int(s) >= 10 and int(s) <= 26)
    
    def numDecodings(self, s: str) -> int:
        n = len(s)
        if n == 1:
            return self.oneNum(s)
        elif n == 2:
            return self.twoNums(s) + int((self.oneNum(s[0]) and self.oneNum(s[1])))
        else:
            dp = []
            dp.append(self.oneNum(s[0]))
            dp.append(self.twoNums(s[0:2]) + int(self.oneNum(s[0]) and self.oneNum(s[1])))
            for i in range(2, n):
                dp.append(self.oneNum(s[i]) * dp[i-1] + self.twoNums(s[i-1:i+1]) * dp[i-2])
            return dp[-1]
        
solution = Solution()
print(solution.numDecodings("189327"))