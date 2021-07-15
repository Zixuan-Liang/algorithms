class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = 1
        while n-i-1>=0 and nums[n-i-1] >= nums[n-i]:
            i += 1
        # low, high = n-i, n-1
        # while low < high:
        #     nums[low], nums[high] = nums[high], nums[low]
        #     low += 1
        #     high -= 1
        nums[n-i:] = nums[n-i:][::-1]
        if n-i-1 >= 0:
            k = n-i
            while nums[k] <= nums[n-i-1]:
                k += 1
            nums[k], nums[n-i-1] = nums[n-i-1], nums[k]
            
# class Solution:
#     def nextPermutation(self, nums: List[int]) -> None:
#         length = len(nums)
#         for i in range(length-1,0,-1):
#             if nums[i] > nums[i - 1]:
#                 for j in range(i+1, length):
#                     if nums[j] <= nums[i-1]:
#                         nums[i - 1], nums[j - 1] = nums[j - 1], nums[i - 1]
#                         nums[i:] = nums[i:][::-1]
#                         return
#                 nums[i - 1], nums[length - 1] = nums[length - 1], nums[i - 1]
#                 nums[i:] = nums[i:][::-1]
#                 return
#         nums[:] = nums[::-1]
        
        