# Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
#
# For example,
# Given n = 3, your program should return all 5 unique BST's shown below.
#
#    1         3     3      2      1
#     \       /     /      / \      \
#      3     2     1      1   3      2
#     /     /       \                 \
#    2     1         2                 3

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import itertools
import copy


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        ans = []
        if n == 0:
            return ans
        ans = [[TreeNode(1)]]
        for i in range(2, n + 1):
            trees = ans[-1]
            new_trees = []
            for tree in trees:
                copy_t = copy.deepcopy(tree)
                new_t = TreeNode(i)
                new_t.left = copy_t
                new_trees.append(new_t)
            for tree in trees:
                count = 0
                node = tree
                while node != None:
                    count += 1
                    node = node.right
                for j in range(count):
                    copy_t = copy.deepcopy(tree)
                    node = copy_t
                    for k in range(j):
                        node = node.right
                    new_n = TreeNode(i)
                    new_n.left = node.right
                    node.right = new_n
                    new_trees.append(copy_t)
            ans.append(new_trees)
        return ans[-1]

    def visit(self, tree):
        if tree == None:
            return
        elif tree.left == None and tree.right == None:
            print tree.val
        else:
            self.visit(tree.left)
            self.visit(tree.right)

s = Solution()
ans = s.generateTrees(2)
print len(ans)
for tree in ans:
    s.visit(tree)

