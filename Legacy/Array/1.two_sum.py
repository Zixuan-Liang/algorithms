from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        length = len(nums)
        for i in range(length):
            comp = target - nums[i]
            if comp in table:
                return [table[comp], i]
            table[nums[i]] = i

solution = Solution()
print(solution.twoSum([2,7,11,15], 9))