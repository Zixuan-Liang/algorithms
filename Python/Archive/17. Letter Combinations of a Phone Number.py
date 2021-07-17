class Solution:

    lookup = [['a', 'b', 'c'], ['d', 'e', 'f'], ['g', 'h', 'i'], 
              ['j', 'k', 'l'], ['m', 'n', 'o'], ['p', 'q', 'r', 's'], 
              ['t', 'u', 'v'], ['w', 'x', 'y', 'z']]
    
    def letterCombinations(self, digits):
        if len(digits) == 0: return []
        ans = []
        comb = ""
        def backtrack(digits, i, ans, comb):
            if i == len(digits):
                ans.append(comb)
            else:
                for c in self.lookup[ord(digits[i]) - ord('2')]:
                    comb += c
                    backtrack(digits, i + 1, ans, comb)
                    comb = comb[:-1]
        backtrack(digits, 0, ans, comb)
        return ans
        