# 前序遍历 根左右
def preorderTraversal(root):
    res, stack = [], []
    while root or stack:
        while root:
            res.append(root.val)
            stack.append(root.left)
            root = root.left
        root = stack.pop()
        root = root.right
    return res

# 后续遍历 左右根 （相当于根右左结果翻转，转化为前序遍历）
def postorderTraversal(root):
    res, stack = [], []
    while root or stack:
        while root:
            res.append(root.val)
            stack.append(root.right)
            root = root.right
        root = stack.pop()
        root = root.left
    return res[::-1]

# 中序遍历 左根右 
def inorderTraversal(root):
    res, stack = [], []
    while root or stack:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        res.append(root.val)
        root = root.right
    return res