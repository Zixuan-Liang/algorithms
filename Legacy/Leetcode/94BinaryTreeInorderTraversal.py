# Given a binary tree, return the inorder traversal of its nodes' values.
#
# For example:
# Given binary tree [1,null,2,3],
#    1
#     \
#      2
#     /
#    3
# return [1,3,2].

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        stack = []
        ans = []
        visit = {}
        stack.append(root)
        while stack:
            node = stack[-1].left
            while node != None and node not in visit:
                stack.append(node)
                node = node.left
            node = stack.pop()
            ans.append(node.val)
            visit[node] = True
            if node.right != None:
                stack.append(node.right)
        return ans

