from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = [float('inf')]
        for i in range(len(nums)):
            self.twoSum(nums, i, target, res)
        return res[0] + target
        
    def twoSum(self, nums, index, target, res):
        left, right = index+1, len(nums)-1
        while left < right:
            s = nums[index] + nums[left] + nums[right]
            if abs(s-target) < abs(res[0]): res[0] = s - target
            if res[0] == 0:
                break
            elif s - target < 0:
                left += 1
            else:
                right -= 1        