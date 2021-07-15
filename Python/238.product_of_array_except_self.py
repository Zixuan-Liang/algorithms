from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        running = 1
        ans = []
        for num in nums:
            running *= num
            ans.append(running)
        running_r = 1
        N = len(nums)
        for i in range(N-1, 0, -1):
            ans[i] = running_r * ans[i-1]
            running_r *= nums[i]
        ans[0] = running_r
        return ans