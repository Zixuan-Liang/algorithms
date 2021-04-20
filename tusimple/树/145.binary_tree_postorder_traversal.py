class Solution(object):
    def postorderTraversal(self, root):
        res, stack = [], []
        while root or stack:
            while root:
                res.append(root.val)
                stack.append(root)
                root = root.right
            root = stack.pop()
            root = root.left
        return res[::-1]