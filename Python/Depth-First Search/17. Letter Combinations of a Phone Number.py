from typing import List

class Solution:
    lookup = ['', '', ['a', 'b', 'c'], ['d', 'e', 'f'], ['g', 'h', 'i'], 
              ['j', 'k', 'l'], ['m', 'n', 'o'], ['p', 'q', 'r', 's'], ['t', 'u', 'v'], ['w', 'x', 'y', 'z']]
    
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0: return []
        firstD = self.lookup[ord(digits[0]) - ord('0')]
        if len(digits) == 1: return firstD
        res = []
        restD = self.letterCombinations(digits[1:])
        for c1 in firstD:
            for c2 in restD:
                res.append(c1 + c2)
        return res
        