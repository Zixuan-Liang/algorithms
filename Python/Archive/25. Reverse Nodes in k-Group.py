# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    
    def getLength(self, head):
        res = 0
        while head:
            res += 1
            head = head.next
        return res
    
    def reverseK(self, head, k):
        if k == 1: return head
        temp = head.next
        res = self.reverseK(head.next, k-1)
        temp.next = head
        return res
    
    def helper(self, head, n, k):
        if n < k: return head
        restHead = head
        for _ in range(k): restHead = restHead.next
        res = self.reverseK(head, k)
        head.next = self.helper(restHead, n-k, k)
        return res
    
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        n = self.getLength(head)
        return self.helper(head, n, k)