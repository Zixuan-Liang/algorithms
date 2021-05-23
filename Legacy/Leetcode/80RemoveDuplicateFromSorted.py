# Follow up for "Remove Duplicates":
# What if duplicates are allowed at most twice?
#
# For example,
# Given sorted array nums = [1,1,1,2,2,3],
#
# Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
# It doesn't matter what you leave beyond the new length.

def remove_duplicates(nums):
    length = len(nums)
    ans = 0
    if length == 0:
        return ans
    start = 0
    end = 0
    insert = 0
    while end < length:
        while end < length and nums[end] == nums[start]:
            end += 1
        if end > start + 1:
            ans += 2
            nums[insert] = nums[insert + 1] = nums[start]
            insert += 2
        else:
            ans += 1
            nums[insert] = nums[start]
            insert += 1
        start = end
    return ans

nums = [1,1,1,2]
print remove_duplicates(nums)
print nums