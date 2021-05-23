# Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
#
# For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
# the contiguous subarray [4,-1,2,1] has the largest sum = 6.

import sys

def merge(nums, mid):
    max_left = - sys.maxint
    max_right = - sys.maxint
    sum_left = 0
    sum_right = 0
    for i in range(mid + 1, len(nums)):
        sum_right += nums[i]
        if sum_right > max_right:
            max_right = sum_right
    for i in range(mid, -1, -1):
        sum_left += nums[i]
        if sum_left > max_left:
            max_left = sum_left
    return max_left + max_right

def max_sub_array(nums):
    if len(nums) == 1:
        return nums[0]
    else:
        start = 0
        end = len(nums) - 1
        mid = start + (end - start) / 2
        return max(max_sub_array(nums[start : mid + 1]), max_sub_array(nums[mid + 1 : end + 1]), merge(nums, mid))

print max_sub_array([-2,1,-3,4,-1,2,1,-5,4])