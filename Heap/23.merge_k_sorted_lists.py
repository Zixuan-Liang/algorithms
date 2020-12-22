# Definition for singly-linked list.
from typing import List
from heapq import heapify, heappush, heappop

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        sol = ListNode(0)
        ans = sol
        pointers = lists
        minsHeap = []
        heapify(minsHeap)
        for i, p in enumerate(pointers):
            # print(i, p)
            if(p):
                heappush(minsHeap, (p.val, i))
        while(len(minsHeap)):
            val, i = heappop(minsHeap)
            sol.next = ListNode(val)
            sol = sol.next
            pointers[i] = pointers[i].next
            if(pointers[i]):
                heappush(minsHeap, (pointers[i].val, i))
        return ans.next

# If we want to put object (not comparable) instead of index into priority queue,
# create a wrapper class inside
# from queue import PriorityQueue

# class Solution():
#     def mergeKLists(self, lists):
#         """
#         :type lists: List[ListNode]
#         :rtype: ListNode
#         """
#         class Wrapper():
#             def __init__(self, node):
#                 self.node = node
#             def __lt__(self, other):
#                 return self.node.val < other.node.val
        
#         head = point = ListNode(0)
#         q = PriorityQueue()
#         for l in lists:
#             if l:
#                 q.put(Wrapper(l))
#         while not q.empty():
#             node = q.get().node
#             point.next = node
#             point = point.next
#             node = node.next
#             if node:
#                 q.put(Wrapper(node))
#         return head.next