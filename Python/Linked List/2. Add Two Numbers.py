# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.helper(l1, l2, 0)
    
    def helper(self, l1, l2, c):
        res = None
        if l1 or l2 or c:
            l1 = ListNode(0) if not l1 else l1
            l2 = ListNode(0) if not l2 else l2
            total = l1.val + l2.val + c
            res = ListNode(total%10)
            res.next = self.helper(l1.next, l2.next, total//10)
        return res