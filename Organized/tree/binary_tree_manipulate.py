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

# 有序数组转换成二叉搜索树
# 二分，从数组中找根节点，数组左边为左树，右边为右树，进行递归
class SolutionSortedArrayToBST:
    def helper(self, lowIdx, highIdx):
        if lowIdx < 0 or highIdx >= len(self.nums) or lowIdx > highIdx:
            return None
        rootIdx = lowIdx + (highIdx - lowIdx)//2
        root = TreeNode(self.nums[rootIdx])
        if lowIdx == highIdx:
            return root
        else:
            root.left = self.helper(lowIdx, rootIdx-1)
            root.right = self.helper(rootIdx+1, highIdx)
            return root

    def sortedArrayToBST(self, nums):
        self.nums = nums
        return self.helper(0, len(self.nums)-1)

# 从中序与后序遍历构造二叉树
# 递归法构造左子树和右子树，从后序遍历确定根（最后一个数），找到该数在中序遍历的索引（事先建立字典方便查询）
# 根据根在中序遍历的索引，分别划分中序遍历和后序遍历为左右数组，然后递归构造左子树和右子树
class SolutionBuildTreeFromInorderPostorder:
    def helper(self, inLowIdx, inHighIdx, postLowIdx, postHighIdx):
        if inLowIdx > inHighIdx or postLowIdx > postHighIdx:
            return None
        root = TreeNode(self.postorder[postHighIdx])
        rootIdx = self.inorderIdx[root.val]
        root.left = self.helper(inLowIdx, rootIdx-1, postLowIdx, postLowIdx+(rootIdx-1-inLowIdx))
        root.right = self.helper(rootIdx+1, inHighIdx, postHighIdx-1-(inHighIdx-rootIdx-1) , postHighIdx-1)
        return root

    def buildTree(self, inorder, postorder):
        self.inorder, self.postorder = inorder, postorder
        # 事先建立中序遍历的索引字典方便查询
        self.inorderIdx = {x: i for i, x in enumerate(self.inorder)}
        return self.helper(0, len(self.inorder)-1, 0, len(self.postorder)-1)

# 从中序与前序遍历构造二叉树
# 与 从中序与后序遍历构造二叉树 类似
class SolutionBuildTreeFromInorderPreorder:
    def helper(self, inLowIdx, inHighIdx, preLowIdx, preHighIdx):
        if inLowIdx > inHighIdx or preLowIdx > preHighIdx:
            return None
        root = TreeNode(self.preorder[preLowIdx])
        rootIdx = self.inorderIdx[root.val]
        root.left = self.helper(inLowIdx, rootIdx-1, preLowIdx+1, preLowIdx+1+(rootIdx-1-inLowIdx))
        root.right = self.helper(rootIdx+1, inHighIdx, preHighIdx-(inHighIdx-rootIdx-1), preHighIdx)
        return root

    def buildTree(self, preorder, inorder):
        self.inorder, self.preorder = inorder, preorder
        # 事先建立中序遍历的索引字典方便查询
        self.inorderIdx = {x: i for i, x in enumerate(self.inorder)}
        return self.helper(0, len(self.inorder)-1, 0, len(self.preorder)-1)