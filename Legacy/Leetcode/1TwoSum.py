# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.

def two_sum(nums, target):
    complement = dict()
    result = [-1, -1]
    for i in range(len(nums)):
        if nums[i] in complement:
            result[0] = complement[nums[i]]
            result[1] = i
            return result
        else:
            complement[target - nums[i]] = i
    return result

print(two_sum([2, 7, 11, 15], 9))