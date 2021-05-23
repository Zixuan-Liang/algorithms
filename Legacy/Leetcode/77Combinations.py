# Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
#
# For example,
# If n = 4 and k = 2, a solution is:
#
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]

import itertools

def combine(n, k):
    ans = []
    candidates = [i + 1 for i in range(n)]
    combs = itertools.combinations(candidates, k)
    for comb in combs:
        ans.append(comb)
    return ans