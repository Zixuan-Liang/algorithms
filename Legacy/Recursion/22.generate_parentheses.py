# class Solution:
#     def generateParenthesis(self, n: int) -> List[str]:
#         ans = []
#         def backtrack(S = '', left = 0, right = 0):
#             if len(S) == 2 * n:
#                 ans.append(S)
#                 return
#             if left < n:
#                 backtrack(S+'(', left+1, right)
#             if right < left:
#                 backtrack(S+')', left, right+1)

#         backtrack()
#         return ans
    
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(N, open=0):
            if N > 0 and 0 <= open:
                return ['(' + p for p in backtrack(N-1, open+1)] + \
                       [')' + p for p in backtrack(N, open-1)]
            return [')' * open] * (not N)
        return backtrack(n)