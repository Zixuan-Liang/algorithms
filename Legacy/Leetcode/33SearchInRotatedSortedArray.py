# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
# You are given a target value to search. If found in the array return its index, otherwise return -1.
# You may assume no duplicate exists in the array.

def search(nums, target):
    l, r = 0, len(nums)-1
    while l <= r:
        mid = l + (r-l)//2
        if nums[mid] == target:
            return True
        while l < mid and nums[l] == nums[mid]: # tricky part
            l += 1
        # the first half is ordered
        if nums[l] <= nums[mid]:
            # target is in the first half
            if nums[l] <= target < nums[mid]:
                r = mid - 1
            else:
                l = mid + 1
        # the second half is ordered
        else:
            # target is in the second half
            if nums[mid] < target <= nums[r]:
                l = mid + 1
            else:
                r = mid - 1
    return False