# Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
#
# For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
#
#     1
#    / \
#   2   2
#  / \ / \
# 3  4 4  3
# But the following [1,2,2,null,3,null,3] is not:
#     1
#    / \
#   2   2
#    \   \
#    3    3

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sym(self, left, right):
        left_none = left == None
        right_none = right == None
        if left_none or right_none:
            return left_none and right_none
        elif left.val != right.val:
            return False
        else:
            return self.sym(left.left, right.right) and self.sym(left.right, right.left)

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        return self.sym(root.left, root.right)