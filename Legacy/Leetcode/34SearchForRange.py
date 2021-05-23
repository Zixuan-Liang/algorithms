# Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8,
# return [3, 4].

def searchRange(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    if not nums:
        return [-1, -1]

    def search(lo, hi):
        if nums[lo] == target == nums[hi]:
            return [lo, hi]
        if nums[lo] <= target <= nums[hi]:
            mid = (lo + hi) / 2
            l, r = search(lo, mid), search(mid + 1, hi)
            return max(l, r) if -1 in l + r else [l[0], r[1]]
        return [-1, -1]

    return search(0, len(nums) - 1)