# 栈：先进后出， 队列：先进先出
# Python: 数据类型                添加        删除      访问栈顶/队列头     特殊
# 栈：      []                   append      pop        stack[-1]         stack[0]栈底
# 队列：   collections.deque     append      popleft    queue[0]          pop为删除队列尾,queue[-1]为访问队列尾

from collections import deque as Queue

# 函数递归用到栈

# 利用栈进行DFS递归搜索模板
# def dfs(root, target):        # root为搜索起始点，target为搜索目标
#   visited = set()             # 创建一个集set，以存储访问过的点
#   visited.add(root)           # 将起始点加入集合
#   stack = []                  # 创建一个栈
#   stack.append(root)          # 搜索起点入栈
#   while stack:                # 当栈非空时，一直循环搜索
#       curr = stack.pop()      # 出栈，当前搜索点
#       return True if curr is target   # 找到了就返回
#       for node in curr.neighbors:  # 从当前搜索点开始，对当前点的邻居逐个进行DFS递归
#           if node not in visited:     # 如果没访问过
#               visited.add(node)       # 加入到已访问的集合
#               stack.append(node)      # 加入到栈
#   return False                        # 如果循环结束（栈已经空了），还没返回，说明找不到，返回False

# 以搜索岛屿数量为例
class SolutionNumIslands:

    # 用栈实现深度优先搜索DFS
    def dfs(self, r, c):                # 整个DFS的工作是，从某个'1'开始，搜索和这个'1'连通的区域，并加入到已访问的集合
        self.grid[r][c] = '0'           # 这里将'1'修改为'0'充当了把点加入到visited集合的作用
        stack = []                          # 创建一个栈
        stack.append((r, c))            # 搜索起点入栈
        while stack:
            r, c = stack.pop()              # 出栈，当前搜索点
            for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:   # 对邻居逐个进行DFS
                if 0<=x<self.rows and 0<=y<self.cols and self.grid[x][y]=='1':    # 等于'1'隐含了没访问过的前提条件
                    self.grid[x][y] = '0' 
                    stack.append((x,y))         # 加入到栈

    # 用队列实现广度优先搜索BFS
    def bfs(self, r, c):
        self.grid[r][c] = '0'
        queue = Queue([(r, c)])
        while queue:
            r, c = queue.popleft()
            for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
                if 0<=x<self.rows and 0<=y<self.cols and self.grid[x][y]=='1':
                    self.grid[x][y] = '0'
                    queue.append((x, y))

    # 用递归实现深度优先搜索DFS
    def dfsResursive(self, r, c):
        self.grid[r][c] = '0'
        for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
            if 0<=x<self.rows and 0<=y<self.cols and self.grid[x][y]=='1':
                self.dfsResursive(x, y)

    def numIslands(self, grid):
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])
        res = 0
        for r in range(self.rows):
            for c in range(self.cols):
                if self.grid[r][c] == '1':
                    res += 1
                    self.dfs(r, c)
        return res
        
# 实现一个栈，常规操作：push, pop, top，特殊操作min，均要求O(1)
# 用两个栈实现，栈A常规操作，栈B只存降序的数，栈B顶即为最小值
class MinStack:

    def __init__(self):
        self.stackA = []
        self.stackB = []

    def push(self, val: int) -> None:
        self.stackA.append(val)
        if not self.stackB or val <= self.stackB[-1]:
            self.stackB.append(val)

    def pop(self) -> None:
        if self.stackA:
            val = self.stackA.pop()
            if val == self.stackB[-1]:
                self.stackB.pop()

    def top(self) -> int:
        return self.stackA[-1]

    def getMin(self) -> int:
        if self.stackB:
            return self.stackB[-1]
        else:
            return None

# 逆波兰式表达式
# 后缀表达式，符号写在后面，好处是不需要括号，没有括号也不会有歧义
# 用栈操作，遇到数字则入栈，遇到运算符号则出栈顶两个数字计算，计算结构再进栈
# 此函数实现假定输入的tokens是合法的
def evalRPN(tokens):
    stack = []
    for token in tokens:
        if token in ['+', '-', '*', '/']:
            num1 = stack.pop()
            num2 = stack.pop()
            if token == '+':
                num = num2 + num1
            elif token == '-':
                num = num2 - num1
            elif token == '*':
                num = num2 * num1
            else:
                num = int(num2 / num1)      # Python的//向下取整这里不能用，因为6//-10会得到-1，这里我们想要得到0
            stack.append(num)
        else:
            stack.append(int(token))
    return stack[-1]

# 解码字符k[encoded_string]，encoded_string重复k次
# 碰到字母或左括号，直接进栈
# 碰到数字串，解析出一个数字，进栈
# 碰到左括号，出栈得到一串字符+'['+一个数字，k x string进栈
# 最后把栈里的字符串组合起来（从栈底到栈顶）
def decodeString(s):
    res = ''
    if not s:
        return res
    stack = []
    i = 0
    while i < len(s):
        if s[i].isdigit():
            k = s[i]
            i += 1
            while i < len(s) and s[i].isdigit():
                k += s[i]
                i += 1
            k = int(k)
            stack.append(k)
        elif s[i].isalpha() or s[i]=='[':
            stack.append(s[i])
            i += 1
        else:
            string = ''
            while stack[-1] != '[':
                string = stack.pop() + string
            stack.pop()
            k = stack.pop()
            stack.append(k * string)
            i += 1
    while stack:
        res = stack.pop() + res
    return res

# 克隆图，深拷贝 copy.deepcopy()
# 深度优先搜索 DFS 递归 recursive
# 也可以利用队列广度优先搜索 BFS 
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class SolutionCloneGraph:

    def __init__(self):
        self.visited = {}
    
    def cloneGraphDFS(self, node):
        if not node:
            return node
        if node in self.visited:
            return self.visited[node]
        cloneNode = Node(node.val, [])
        self.visited[node] = cloneNode
        if node.neighbors:
            cloneNode.neighbors = [self.cloneGraph(n) for n in node.neighrbors]
        return cloneNode

    def cloneGraphBFS(self, node):
        if not node:
            return node
        visited = {}
        queue = Queue([node])
        visited[node] = Node(node.val, [])
        while queue:
            n = queue.popleft()
            for neighbor in n.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = Node(neighbor.val, [])
                    queue.append(neighbor)
                visited[n].neighbors.append(visited[neighbor])
        return visited[node]

# 柱状图中最大的矩形
def largestRectangleArea(heights):
    pass