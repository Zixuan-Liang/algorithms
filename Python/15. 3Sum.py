from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        index = 0
        while index < len(nums) and nums[index] <= 0:
            if index == 0 or (nums[index-1] != nums[index]):
                self.twoSum(nums, index, res)
            index += 1
        return res
        
    def twoSum(self, nums, index, res):
        left, right = index+1, len(nums)-1
        while left < right:
            s = nums[index] + nums[left] + nums[right]
            if s == 0:
                res.append([nums[index], nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left]==nums[left-1]: left += 1
            elif s < 0:
                left += 1
            else:
                right -= 1