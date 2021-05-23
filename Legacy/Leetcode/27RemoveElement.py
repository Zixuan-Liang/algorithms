# Given an array and a value, remove all instances of that value in place and return the new length.
# Do not allocate extra space for another array, you must do this in place with constant memory.
# The order of elements can be changed. It doesn't matter what you leave beyond the new length.

def remove_element(nums, val):
    begin = 0
    for i in range(len(nums)):
        if nums[i] != val:
            nums[begin] = nums[i]
            begin += 1
    return begin

print remove_element([3, 2, 2, 3], 3)