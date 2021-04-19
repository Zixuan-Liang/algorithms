# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    
    def helper(self, root):
        if not root:
            return 0
        left = max(0, self.helper(root.left))
        right = max(0, self.helper(root.right))
        ans = root.val + max(left, right)
        bothWay = root.val + left + right
        self.res = max(self.res, bothWay, ans)
        return ans

    def maxPathSum(self, root):
        self.res = -float('inf')
        
        self.helper(root)

        return self.res