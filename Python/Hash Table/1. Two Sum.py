from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memo = {}
        for i, n in enumerate(nums):
            if n in memo:
                return [memo[n], i]
            memo[target - n] = i
        return []