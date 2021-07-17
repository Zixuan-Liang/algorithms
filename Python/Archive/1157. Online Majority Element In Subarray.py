from bisect import bisect_left, bisect_right
from collections import defaultdict

class MajorityChecker:

    def __init__(self, arr):
        self.pos = defaultdict(list)
        for i in range(len(arr)):
            self.pos[arr[i]].append(i)
        self.n = len(arr)
        self.tree = [-1] * (4 * self.n)
        self.vec = arr
        self.buildTree(1, 0, self.n - 1)
        
    def buildTree(self, treePos, left, right):
        if left == right:
            self.tree[treePos] = self.vec[left]
            return
        mid = left + (right - left) // 2
        self.buildTree(treePos * 2, left, mid)
        self.buildTree(treePos * 2 + 1, mid + 1, right)
        if self.tree[treePos * 2] != -1 and self.getOccurence(self.tree[treePos * 2], left, right) * 2 > right - left + 1:
            self.tree[treePos] = self.tree[treePos * 2]
        elif self.tree[treePos * 2 + 1] != -1 and self.getOccurence(self.tree[treePos * 2 + 1], left, right) * 2 > right - left + 1:
            self.tree[treePos] = self.tree[treePos * 2 + 1]

    def getOccurence(self, num, left, right):
        lb = bisect_left(self.pos[num], left)
        ub = bisect_right(self.pos[num], right)
        return ub - lb
            
    def treeQuery(self, treePos, left, right, queryL, queryR):
        if left > queryR or right < queryL:
            return (-1, -1)
        if queryL <= left and right <= queryR:
            if self.tree[treePos] == -1:
                return (-1, -1)
            occ = self.getOccurence(self.tree[treePos], queryL, queryR)
            if occ * 2 > queryR - queryL + 1:
                return (self.tree[treePos], occ)
            else:
                return (-1, -1)
        mid = left + (right - left) // 2
        resL = self.treeQuery(treePos * 2, left, mid, queryL, queryR)
        if resL[0] > -1:
            return resL
        resR = self.treeQuery(treePos * 2 + 1, mid + 1, right, queryL, queryR)
        if resR[0] > -1:
            return resR
        return (-1, -1)
        
    def query(self, left: int, right: int, threshold: int) -> int:
        ans = self.treeQuery(1, 0, self.n - 1, left, right)
        if ans[1] >= threshold:
            return ans[0]
        else:
            return -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)