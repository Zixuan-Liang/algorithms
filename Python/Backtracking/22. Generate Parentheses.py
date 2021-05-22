from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def helper(s, open_, close_):
            if len(s) == 2*n and open_ == n and close_ == n:
                res.append(s)
            if open_+1 <= n:
                helper(s+'(', open_+1, close_)
            if close_+1 <= n and open_ > close_:
                helper(s+')', open_, close_+1)
        helper('', 0, 0)
        return res