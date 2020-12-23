from typing import List
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        else:
            numbers = [str(i) for i in range(2, 10)]
            letters = [['a','b','c'],['d','e','f'],
                       ['g','h','i'],['j','k','l'],['m','n','o'],
                       ['p','q','r','s'],['t','u','v'],['w','x','y','z']]
            table = dict(zip(numbers, letters))
            combs = table[digits[0]]
            if len(digits) == 1:
                return combs
            else:
                return [i+j for i in combs for j in self.letterCombinations(digits[1:])]

# import itertools

# def letter_com(digits):
#     length = len(digits)
#     if length ==  0:
#         return []
#     bucket = ['' for i in range(length)]
#     dict = {'1':'', '2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
#     for i in range(length):
#         bucket[i] = dict[digits[i]]
#     result = list(itertools.product(*bucket))
#     result = [''.join(ele) for ele in result]
#     return result

# print letter_com("23")