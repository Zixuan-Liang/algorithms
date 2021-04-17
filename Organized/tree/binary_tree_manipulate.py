# 对二叉树进行修改操作

# 对于二叉树的问题，搞清楚根节点应该做什么，
# 然后剩下的事情交给前/中/后序遍历框架就行了，千万不要跳进递归的细节里

from collections import deque as Queue

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

# 从前序遍历和后序遍历不能重建二叉树
# 可以从 前序遍历/后序遍历/层序遍历 重建二叉搜索树（不含重复元素）
# 二叉搜索树的中序遍历是一个排好序的数组

# 从中序与后序遍历构造二叉树（不含重复元素）
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

# 从中序与前序遍历构造二叉树（不含重复元素）
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

# 对于一个完美二叉树，填充每个节点的下一个右侧节点指针
# BFS 层次遍历
def connect(root):
    if not root:
        return None
    queue = Queue()
    queue.append(root)
    while queue:
        levelLen = len(queue)
        for i in range(levelLen):
            node = queue.popleft()
            if i < levelLen-1:
                node.next = queue[0]
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    return root

# 或者用递归方式 DFS
class SolutionConnect:
    def helper(self, node1, node2):
        if not node1 or not node2:
            return
        node1.next = node2
        self.helper(node1.left, node1.right)
        self.helper(node2.left, node2.right)
        self.helper(node1.right, node2.left)

    def connect(self, root):
        if not root:
            return root
        self.helper(root.left, root.right)
        return root

# 二叉树序列化、反序列化
# 序列化：输入二叉树用一个字符串来编码；反序列化：把输入字符串解码为一个二叉树
# 编码：带空指针的层序遍历 BFS
# 解码：同样用队列来重建二叉树
class Codec:
    def serialize(self, root):
        if not root:
            return ''
        res = []
        queue = Queue()
        queue.append(root)
        while queue:
            node = queue.popleft()
            if not node:
                res.append('#')
            else:
                res.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
        return ','.join(res)

    def deserialize(self, data):
        if not data:
            return None
        traversal = data.split(',')
        queue = Queue()
        root = TreeNode(int(traversal[0]))
        queue.append(root)
        i = 1
        while i < len(traversal):
            parent = queue.popleft()
            if traversal[i] != '#':
                left = TreeNode(int(traversal[i]))
                parent.left = left
                queue.append(left)
            if i+1<len(traversal) and traversal[i+1] != '#':
                right = TreeNode(int(traversal[i+1]))
                parent.right = right
                queue.append(right)
            i += 2
        return root

# 用递归实现序列化/反序列化
class CodecRecursive:
    def serializeHelper(self, root):
        if not root:
            self.string += '#,'
            return
        self.string += str(root.val) + ','
        self.serializeHelper(root.left)
        self.serializeHelper(root.right)

    def serialize(self, root):
        self.string = ''
        self.serializeHelper(root)
        return self.string

    def deserializeHelper(self):
        if not self.nodes:
            return None
        first = self.nodes.popleft()
        if first == '#':
            return None
        root = TreeNode(int(first))
        root.left = self.deserializeHelper()
        root.right = self.deserializeHelper()
        return root

    def deserialize(self, data):
        self.nodes = Queue()
        for s in data.split(','):
            self.nodes.append(s)
        return self.deserializeHelper()

# 堆(heap)是二叉树的一种，最小堆：根节点是树最小值，左右子树也是最小堆
# 堆又叫优先队列，最小堆就是最小优先队列，无论入堆顺序如何，出堆总是最小的出堆
# Python自带最小堆库：import heapq （如果要用最大堆，入堆前用-val即可）

# 以数组形式表示堆：leftIndex = parentIndex * 2 + 1, rightIndex = parentIndex * 2 + 2

# 从空数组开始构造最小堆：
# heap = []
# heapq.heappush(heap, 3)   # 入堆操作
# val = heap[0]     # 读取堆顶数值
# val = heapq.heappop(heap)     # 出堆操作

# 入堆/出堆后，都要维护堆的性质，复杂度为O(lgn)（复杂度为树的高度）

# 从一个已有数组构造最小堆
# x = [1,6,7,4,2,9]
# heapq.heapify(x)      # 将数组按照最小堆的性质重新排序，heapify的复杂度为O(n)
# small = heapq.nsmallest(3, x)   # 读取堆的最小n个元素（并不修改，只是读取）

# 翻转二叉树
def invertTree(root):
    if not root:
        return root
    root.left, root.right = root.right, root.left
    invertTree(root.left)
    invertTree(root.right)
    return root

# 二叉树展开为链表
# 步骤一：明确递归函数的定义，将以root为根的树拉平为链表
# 步骤二：后序遍历，将左子树拉平，右子树拉平，最后拼接到根
def flatten(root):
    if not root:
        return
    flatten(root.left)
    flatten(root.right)
    oldRight = root.right
    root.right = root.left
    root.left = None
    node = root
    while node.right:
        node = node.right
    node.right = oldRight

# 用一个不含重复元素的数组构造最大二叉树（最大堆）
class SolutionConstructMaximumBinaryTree:
    def getMaxIdx(self, low, high):
        maxIdx = low
        for i in range(low, high+1):
            if self.nums[i] > self.nums[maxIdx]:
                maxIdx = i
        return maxIdx

    def helper(self, low, high):
        if low > high:
            return None
        maxIdx = self.getMaxIdx(low, high)
        root = TreeNode(self.nums[maxIdx])
        root.left = self.helper(low, maxIdx-1)
        root.right = self.helper(maxIdx+1, high)
        return root

    def constructMaximumBinaryTree(self, nums):
        self.nums = nums
        return self.helper(0, len(nums)-1)

# 二叉搜索树转化为累加树
# 确定遍历顺序：右根左（伪中序遍历，因为要从大到小遍历）
# 确定每个节点要做的事情：把自己的值加到一个累加的值，然后更新自己的值
class SolutionConvertBST:
    def helper(self, root):
        if not root:
            return
        self.helper(root.right) # 遍历右
        self.sums += root.val   # 根: 做每个节点要做的事情
        root.val = self.sums
        self.helper(root.left)  # 遍历左

    def convertBST(self, root):
        self.sums = 0
        self.helper(root)
        return root