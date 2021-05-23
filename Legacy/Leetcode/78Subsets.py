# Given a set of distinct integers, nums, return all possible subsets.
#
# Note: The solution set must not contain duplicate subsets.
#
# For example,
# If nums = [1,2,3], a solution is:
#
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]

import itertools

def subsets(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    ans = []
    length = len(nums)
    for i in range(length + 1):
        combs = itertools.combinations(nums, i)
        for comb in combs:
            ans.append(comb)
    return ans