from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        ans, current = 0, 0
        stack = []
        length = len(height)
        while current < length:
            stack.append(current)
            current += 1
            while len(stack) != 0 and current < length and height[current] > height[stack[-1]]:
                top = stack[-1]
                stack.pop()
                if len(stack) == 0:
                    break
                distance = current - stack[-1] - 1
                bounded_height = min(height[current], height[stack[-1]]) - height[top]
                ans += distance * bounded_height
        return ans