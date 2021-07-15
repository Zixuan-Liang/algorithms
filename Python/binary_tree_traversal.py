from collections import deque as Queue

# 只要是遍历二叉树，复杂度都是（节点数为n）:
# O(n)时间，O(n)空间，平均O(lg n)空间，最坏O(n)空间（树为链表）
# 空间取决于队列/栈开销，不会存储超过n个节点

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# DFS 深度优先搜索遍历包括：前序、中序、后序
# 前序遍历 根左右 迭代法 iterative
def preorderTraversal(root):
    res, stack = [], []
    while root or stack:
        while root:
            res.append(root.val)
            stack.append(root)
            root = root.left
        root = root[-1].right
        stack.pop()
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

# 层序遍历 逐层 从上到下 从左到右 BFS 广度优先搜索
def levelOrder(root):
    res = []
    if not root:
        return res
    queue = Queue()
    queue.append(root)
    while queue:
        level = []
        for i in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        res.append(level)
    return res

# 层序遍历 逐层 从下到上 从左到右 BFS 广度优先搜索
def levelOrderBottom(root):
    return levelOrder(root)[::-1]

# 层序遍历 逐层 从下到上 Zigzag BFS 广度优先搜索
def levelOrder(root):
    res = []
    if not root:
        return res
    queue = Queue()
    queue.append(root)
    while queue:
        level = []
        for i in range(len(queue)):
            node = queue.popleft()
            level.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        rightToLeft = len(res) % 2 != 0
        if rightToLeft:
            level = level[::-1]
        res.append(level)
    return 
