class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        count = 1
        for ch in s:
            count = 1 if (not stack or stack[-1][0]!=ch) else stack[-1][1]+1
            stack.append((ch, count))
            if stack[-1][1]>=k:
                for _ in range(k):
                    stack.pop()
        res = ""
        for ch, count in stack:
            res += ch
        return res