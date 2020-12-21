from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    #     sentinel = ListNode()
    #     current_node = sentinel
    #     while l1 and l2:
    #         new_node = ListNode()
    #         value = min(l1.val, l2.val)
    #         new_node.val = value
    #         current_node.next = new_node
    #         current_node = new_node
    #         if value == l1.val:
    #             l1 = l1.next
    #         else:
    #             l2 = l2.next
    #     current_node.next = l1 or l2
    #     return sentinel.next
    
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        elif l1.val <= l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2