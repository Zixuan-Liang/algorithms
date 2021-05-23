# Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
# Find all unique triplets in the array which gives the sum of zero.

def three_sum(nums):
    result = []
    nums.sort()
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        low, high = i + 1, len(nums) - 1
        while low < high:
            s = nums[i] + nums[low] + nums[high]
            if s < 0:
                low += 1
            elif s > 0:
                high -= 1
            else:
                result.append([nums[i], nums[low], nums[high]])
                while low < high and nums[low] == nums[low + 1]:
                    low += 1
                while low < high and nums[high] == nums[high - 1]:
                    high -= 1
                low += 1
                high -= 1
    return result

print three_sum([-1, 0, 1, 2, -1, -4])
