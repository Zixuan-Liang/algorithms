# Given a collection of integers that might contain duplicates, nums, return all possible subsets.
#
# Note: The solution set must not contain duplicate subsets.
#
# For example,
# If nums = [1,2,2], a solution is:
#
# [
#   [2],
#   [1],
#   [1,2,2],
#   [2,2],
#   [1,2],
#   []
# ]

import itertools

def subsetsWithDup(nums):
    length = len(nums)
    ans = []
    for i in range(length + 1):
        combs = itertools.combinations(nums, i)
        for comb in combs:
            comb = sorted(list(comb))
            if comb not in ans:
                ans.append(comb)
    return ans