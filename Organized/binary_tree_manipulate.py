# 对二叉树进行修改操作

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 二叉搜索树的插入操作
def insertIntoBST(root, val):
    if not root:
        return TreeNode(val)
    elif val == root.val:
        node = TreeNode(val)
        node.left, node.right = root.left, root
        return node
    elif val < root.val:
        root.left = insertIntoBST(root.left, val)
        return root
    else:
        root.right = insertIntoBST(root.right, val)
        return root