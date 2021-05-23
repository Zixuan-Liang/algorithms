# Given a collection of distinct numbers, return all possible permutations.
#
# For example,
# [1,2,3] have the following permutations:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]

import itertools

def permute(nums):
    ans = []
    combs = itertools.permutations(nums)
    for comb in combs:
        ans.append(comb)
    return ans
