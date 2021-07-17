class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        count = 1
        for c in s:
            count = 1 if (not stack or stack[-1][0]!=c) else stack[-1][1]+1
            stack.append((c, count))
            if stack[-1][1] >= k:
                for _ in range(k):
                    stack.pop()
        res = ""
        for c, count in stack:
            res += c
        return res