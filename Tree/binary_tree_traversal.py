# 前序遍历 根左右 迭代法 iterative
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

# 前序遍历 根左右 递归法 recursive
def preoderTraversal(root):
    res = []
    if not root:
        return res
    res = [root.val] + preoderTraversal(root.left) + preoderTraversal(root.right)
    return res

# 后序遍历 左右根 迭代法（相当于根右左结果翻转，转化为左右互换顺序的前序遍历）
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

# 后序遍历 左右根 递归法
def postorderTraversal(root):
    res = []
    if not root:
        return res
    res = postorderTraversal(root.left) + [root.val] + postorderTraversal(root.right)
    return res

# 中序遍历 左根右 迭代法
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

# 中序遍历 左根右 递归法
def inorderTraversal(root):
    res = []
    if not root:
        return res
    res = inorderTraversal(root.left) + [root.val] + inorderTraversal(root.right)
    return res

# 