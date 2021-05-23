# Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
# Return the sum of the three integers.
# You may assume that each input would have exactly one solution.
def three_sum_close(nums, target):
    nums.sort()
    result = nums[0] + nums[1] + nums[2]
    for i in range(len(nums) - 2):
        j, k = i + 1, len(nums) - 1
        while j < k:
            summary = nums[i] + nums[j] + nums[k]
            if summary == target:
                return summary
            if abs(target - summary) < abs(result - target):
                result = summary
            if summary < target:
                j += 1
            elif summary > target:
                k -= 1
    return result