"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        self.first = None
        self.last = None
        
        def helper(root):
            if root:
                helper(root.left)
                if self.last:
                    self.last.right = root
                    root.left = self.last
                else:
                    self.first = root
                self.last = root
                helper(root.right)
        
        if not root:
            return None
        helper(root)
        self.last.right = self.first
        self.first.left = self.last
        return self.first
        