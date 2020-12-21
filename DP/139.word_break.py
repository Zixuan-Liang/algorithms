from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        words = set(wordDict)
        dp = [1] + [0 for i in range(n)]
        for i in range(1, n+1):
            for j in range(1, i+1):
                if dp[j-1] == 1 and s[j-1:i] in words:
                    dp[i] = 1
        if dp[-1] == 1:
            return True
        else:
            return False
                    