# Given a collection of candidate numbers (C) and a target number (T),
# find all unique combinations in C where the candidate numbers sums to T.
#
# Each number in C may only be used once in the combination.
#
# Note:
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
# A solution set is:
# [
#   [1, 7],
#   [1, 2, 5],
#   [2, 6],
#   [1, 1, 6]
# ]

def com_sum(candidates, target):
    candidates.sort()
    ans = []
    dfs(candidates, target, 0, [], ans)
    ans = list(set(map(tuple, ans)))
    return ans

def dfs(candidates, target, index, path, ans):
    if target < 0:
        return
    if target == 0:
        ans.append(path)
        return
    for i in range(index, len(candidates)):
        dfs(candidates, target - candidates[i], i + 1, path + [candidates[i]], ans)

print com_sum([10, 1, 2, 7, 6, 1, 5], 8)