from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        return self.kSum(nums, target, 0, 4)
        
    def kSum(self, nums, target, start, k):
        res = []
        if start == len(nums) or nums[start] * k > target or target > nums[-1] * k:
            return res
        if k == 2:
            return self.twoSum(nums, target, start)
        for i in range(start, len(nums)):
            if i == start or nums[i-1] != nums[i]:
                for arr in self.kSum(nums, target-nums[i], i+1, k-1):
                    res.append([nums[i]] + arr)
        return res
    
    def twoSum(self, nums, target, start):
        left, right = start, len(nums)-1
        res = []
        while left < right:
            s = nums[left] + nums[right]
            if s == target:
                res.append([nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left] == nums[left-1]: left += 1
            elif s < target:
                left += 1
            else:
                right -= 1
        return res