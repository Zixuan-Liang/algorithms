# Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#
# You may assume no duplicates in the array.
#
# Here are few examples.
# [1,3,5,6], 5 → 2
# [1,3,5,6], 2 → 1
# [1,3,5,6], 7 → 4
# [1,3,5,6], 0 → 0

def searchInsert(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    start, end = 0, len(nums) - 1
    while (start < end):
        mid = start + (end - start) / 2
        if (nums[mid] == target):
            return mid
        elif (nums[mid] < target):
            start = mid + 1
        else:
            end = mid
    if target > nums[start]:
        return start + 1
    else:
        return start