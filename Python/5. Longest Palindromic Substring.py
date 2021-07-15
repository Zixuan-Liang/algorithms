class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 1: return s
        if n == 2: return s if s[0]==s[1] else s[0]
        # row 0 for even length, row 1 for odd length
        memo = [[0 for _ in range(n)], [1 for _ in range(n)]]
        subStrLen = 1
        endIdx = 0
        for i in range(1, n):
            if s[i]==s[i-1]:
                memo[0][i] = 1
                subStrLen = 2
                endIdx = i
        # substring length starting from 3 up to n
        for i in range(3, n+1):
            row = i%2
            # end index starting from n-1 down to i-1
            for j in range(n-1, i-2, -1):
                memo[row][j] = 0
                if memo[row][j-1] == 1 and s[j]==s[j-i+1]:
                    memo[row][j] = 1
                    subStrLen = i
                    endIdx = j
        return s[endIdx-subStrLen+1:endIdx+1]
        