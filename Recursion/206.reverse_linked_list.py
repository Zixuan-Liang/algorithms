# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        if head.next is None:
            return head
        ans = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return ans

    # def reverseList(self, head: ListNode) -> ListNode:
    #     prev = None
    #     curr = head
    #     while curr:
    #         next_temp = curr.next
    #         curr.next = prev
    #         prev = curr
    #         curr = next_temp
    #     return prev