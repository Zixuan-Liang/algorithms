# 栈：先进后出， 队列：先进先出
# Python: 数据类型                添加        删除      访问栈顶/队列头     特殊
# 栈：      []                   append      pop        stack[-1]         stack[0]栈底
# 队列：   collections.deque     append      popleft    queue[0]          pop为删除队列尾,queue[-1]为访问队列尾

from collections import deque as Queue

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
    def dfs(self, row, col):                # 整个DFS的工作是，从某个'1'开始，搜索和这个'1'连通的区域，并加入到已访问的集合
        self.visited.add((row, col))        # 将起始点加入集合
        stack = []                          # 创建一个栈
        stack.append((row, col))            # 搜索起点入栈
        while stack:
            r, c = stack.pop()              # 出栈，当前搜索点
            for x, y in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:   # 对邻居组个进行DFS
                if (x,y) not in self.visited and 0<=x<self.rows and 0<=y<self.cols and self.grid[x][y]=='1':    # 如果没访问过
                    self.visited.add((x, y))    # 加入到已访问的集合
                    stack.append((x,y))         # 加入到栈

    def numIslands(self, grid):
        self.grid = grid
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.visited = set()
        res = 0
        for r in range(self.rows):
            for c in range(self.cols):
                if self.grid[r][c] == '1' and (r,c) not in self.visited:
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