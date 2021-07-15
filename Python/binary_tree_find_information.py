# 从二叉树中获取某种信息，判断二叉树的一些属性
# 经常用到分治法
# 二叉树从定义上就是递归性质(子树也是一棵树)，所以应用递归可以方便解决问题

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 二叉树最大深度
def maxDepth(root):
    if not root:
        return 0
    return 1 + max(maxDepth(root.left), maxDepth(root.right))

# 判断二叉树是否平衡（子树高度差不超过1）
def isBalancedAndHeight(root):
    if not root:
        return True, 0
    lBalanced, lHeight = isBalancedAndHeight(root.left)
    rBalanced, rHeight = isBalancedAndHeight(root.right)
    balanced = lBalanced and rBalanced and abs(lHeight-rHeight)<=1
    height = 1 + max(lHeight, rHeight)
    return balanced, height

def isBalanced(root):
    balanced, height = isBalancedAndHeight(root)
    return balanced

# 二叉树最大路径和，任意节点出发，到达任意节点
# 分治法，左最大路径和，右最大路径和，合并左右，维护并更新一个global max
def maxPathSum(root):
    res = -float('inf')
    def helper(root):
        nonlocal res
        if not root:
            return 0
        left = max(0, helper(root.left))
        right = max(0, helper(root.right))
        oneWay = root.val + max(left, right)
        res = max(res, oneWay, root.val+left+right)
        return oneWay
    helper(root)
    return res

# 二叉树最近公共祖先 分治法 DFS 深度优先搜索
# 判断左/右树是否包含p或q节点
def lowestCommonAncestor(root, p, q):
    if root in [None, p, q]:
        return root
    left = lowestCommonAncestor(root.left, p, q)
    right = lowestCommonAncestor(root.right, p, q)
    if left and right:
        return root
    elif left:
        return left
    elif right:
        return right
    else:
        return None

# 验证二叉树是否二叉搜索树
# 分治法，要返回左右子树的信息，是否二叉搜索、最大值、最小值
def isValidBSTHelper(root):
    if not root:
        return True, -float('inf'), float('inf')
    left = isValidBSTHelper(root.left)
    right = isValidBSTHelper(root.right)
    rootMax, rootMin = max(root.val, left[1], right[1]), min(root.val, left[2], right[2])
    if left[0] and right[0] and root.val>left[1] and root.val<right[2]:
        return True, rootMax, rootMin,
    else:
        return False, rootMax, rootMin
    
def isValidBST(root):
    return isValidBSTHelper(root)[0]

# 寻找重复的子树
class SolutionFindDuplicateSubtrees:
    def helper(self, root):
        if not root:
            return '#'
        left = self.helper(root.left)
        right = self.helper(root.right)
        subTree = left + ',' + right + ',' + str(root.val)
        if subTree not in self.memo:
            self.memo[subTree] = 0
        if self.memo[subTree] == 1:
            self.res.append(root)
        self.memo[subTree] += 1
        return subTree

    def findDuplicateSubtrees(self, root):
        self.memo = {}
        self.res = []
        self.helper(root)
        return self.res

# 二叉搜索树的问题，要么利用左小右大的特性提升算法效率，
# 要么利用中序遍历的特性满足题目的要求

# 二叉搜索树中第k小的元素
# 中序遍历时，遍历到第k个数就是第k小的元素
class SolutionKthSmallest:
    def helper(self, root, k):
        if not root:
            return
        self.helper(root.left, k)
        self.rank += 1
        if k == self.rank:
            self.res = root.val
            return
        self.helper(root.right, k)

    def kthSmallest(self, root, k):
        self.res = 0
        self.rank = 0
        self.helper(root, k)
        return self.res