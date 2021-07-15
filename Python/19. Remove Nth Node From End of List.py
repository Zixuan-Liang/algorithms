# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(next=head)
        prev, back, front = dummy, head, head
        for _ in range(n - 1): front = front.next
        while front.next:
            prev = back
            front = front.next
            back = back.next
        prev.next = back.next
        return dummy.next