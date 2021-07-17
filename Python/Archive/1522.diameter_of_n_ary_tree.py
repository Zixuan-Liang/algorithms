"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:

    def helper(self, root):
        if not root or not root.children:
            ret, twoWay = 0, 0
        else:
            children = []
            for child in root.children:
                children.append(self.helper(child))
            children.sort()
            if len(children) == 1:
                ret, twoWay = children[-1]+1, children[-1]+1
            else:
                ret, twoWay = children[-1]+1, children[-1]+children[-2]+2
        self.res = max(self.res, twoWay)
        return ret

    def diameter(self, root):
        """
        :type root: 'Node'
        :rtype: int
        """
        if not root:
            return 0
        self.res = -float('inf')
        self.helper(root)
        return self.res