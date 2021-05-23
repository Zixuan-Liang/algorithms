# Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
# If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
# The replacement must be in-place, do not allocate extra memory.
# Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

def next_permutation(nums):
    length = len(nums)
    for i in range(length-1,0,-1):
        if nums[i] > nums[i - 1]:
            for j in range(i+1, length):
                if nums[j] <= nums[i-1]:
                    nums[i - 1], nums[j - 1] = nums[j - 1], nums[i - 1]
                    nums[i:] = nums[i:][::-1]
                    return
            nums[i - 1], nums[length - 1] = nums[length - 1], nums[i - 1]
            nums[i:] = nums[i:][::-1]
            return
    nums[:] = nums[::-1]