from typing import List

class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = [0]
        for i in range(len(nums)):
            self.twoSum(nums, i, target, res)
        return res[0]
            
    def twoSum(self, nums, index, target, res):
        left, right = index+1, len(nums)-1
        while left < right:
            s = nums[index] + nums[left] + nums[right]
            if s < target:
                res[0] += right - left
                left += 1
            else:
                right -= 1