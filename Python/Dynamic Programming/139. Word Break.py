class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = set(wordDict)
        n = len(s)
        dp = [False for _ in range(n+1)]
        dp[0] = True
        for i in range(1, n+1):
            for j in range(max(0, i-20), i):
                tmp = dp[j] and s[j:i] in wordDict
                if tmp: 
                    dp[i] = True
                    break
        return dp[n]
            