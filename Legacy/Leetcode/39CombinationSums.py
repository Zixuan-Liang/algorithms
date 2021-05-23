# Given a set of candidate numbers (C) (without duplicates) and a target number (T),
# find all unique combinations in C where the candidate numbers sums to T.
#
# The same repeated number may be chosen from C unlimited number of times.
#
# Note:
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
# For example, given candidate set [2, 3, 6, 7] and target 7,
# A solution set is:
# [
#   [7],
#   [2, 2, 3]
# ]

def combination_sums(candidates, target):
    ans = []
    candidates.sort()
    dfs(candidates, target, 0, [], ans)
    return ans

def dfs(candidates, target, index, path, ans):
    if target < 0:
        return
    if target == 0:
        ans.append(path)
        return
    for i in range(index, len(candidates)):
        dfs(candidates, target - candidates[i], i, path + [candidates[i]], ans)

print combination_sums([2,3,6,7], 7)
