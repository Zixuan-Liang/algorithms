class Solution(object):
    def helper(self, i, j):
        if (i, j) not in self.memo:
            if j == len(self.pattern):
                ans = i == len(self.text)
            else:
                first_match = i < len(self.text) and self.pattern[j] in {self.text[i], '.'}
                if j + 1 < len(self.pattern) and self.pattern[j+1] == "*":
                    ans = self.helper(i, j+2) or first_match and self.helper(i+1, j)
                else:
                    ans = first_match and self.helper(i+1, j+1)
            self.memo[i, j] = ans
        return self.memo[i, j]
        
                
    def isMatch(self, text, pattern):
        self.memo = {}
        self.text = text
        self.pattern = pattern
        
        return self.helper(0, 0)