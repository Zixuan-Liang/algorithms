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