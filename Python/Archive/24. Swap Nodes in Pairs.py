# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        ans = head.next
        rest = self.swapPairs(head.next.next)
        head.next.next = head
        head.next = rest
        return ans