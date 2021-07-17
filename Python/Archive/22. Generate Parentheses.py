class Solution:
    def generateParenthesis(self, n):
        res = []
        def backtrack(s, open_, close_):
            if len(s) == 2*n and open_ == n and close_ == n:
                res.append(s)
            if open_+1 <= n:
                backtrack(s+'(', open_+1, close_)
            if close_+1 <= n and open_ > close_:
                backtrack(s+')', open_, close_+1)
        backtrack('', 0, 0)
        return res