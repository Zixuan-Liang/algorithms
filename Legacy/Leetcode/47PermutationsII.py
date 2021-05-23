# Given a collection of numbers that might contain duplicates, return all possible unique permutations.
#
# For example,
# [1,1,2] have the following unique permutations:
# [
#   [1,1,2],
#   [1,2,1],
#   [2,1,1]
# ]

import itertools

def permuteUnique(nums):
    combs = itertools.permutations(nums)
    ans = set()
    for comb in combs:
        if comb not in ans:
            ans.add(comb)
    return list(ans)
