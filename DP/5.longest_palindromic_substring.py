# Dynamic programming
# Find 1-letter palindromes, then 2-letter palindromes, etc.
# n x n dp table.

def lps(string):
    n = len(string)
    dp = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        dp[i][i] = 1
    ans = [0, 0]
    for i in range(n - 1):
        if string[i] == string[i+1]:
            dp[i][i+1] = 1
            ans = [i, i+1]
    for i in range(3, n+1):
        for j in range(n-i+1):
            if (string[j] == string[j+i-1]) and dp[j+1][j+i-2]:
                dp[j][j+i-1] = 1
                ans = [j, j+i-1]
    return string[ans[0]:ans[1]+1]

print(lps("cbbd"))
print(lps("aaaaa"))