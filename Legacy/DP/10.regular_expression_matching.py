# class Solution(object):
#     def isMatch(self, text, pattern):
#         if not pattern:
#             return not text

#         first_match = bool(text) and pattern[0] in {text[0], '.'}

#         if len(pattern) >= 2 and pattern[1] == '*':
#             return (self.isMatch(text, pattern[2:]) or
#                     first_match and self.isMatch(text[1:], pattern))
#         else:
#             return first_match and self.isMatch(text[1:], pattern[1:])
    
class Solution(object):
    def solve(self, i, j):
        if (i, j) not in self.memo:
            if j == len(self.pattern):
                ans = i == len(self.text)
            else:
                first_match = i < len(self.text) and self.pattern[j] in {self.text[i], '.'}
                if j + 1 < len(self.pattern) and self.pattern[j+1] == "*":
                    ans = self.solve(i, j+2) or first_match and self.solve(i+1, j)
                else:
                    ans = first_match and self.solve(i+1, j+1)
            self.memo[i, j] = ans
        return self.memo[i, j]
        
                
    def isMatch(self, text, pattern):
        self.memo = {}
        self.text = text
        self.pattern = pattern
        
        return self.solve(0, 0)