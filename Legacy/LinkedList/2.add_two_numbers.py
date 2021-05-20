# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sentinel = ListNode()
        carry = 0
        current_node = sentinel
        while l1 and l2:
            new_node = ListNode()
            current_node.next = new_node
            current_node = new_node
            cal = carry + l1.val + l2.val
            new_node.val = cal % 10
            carry = cal // 10
            l1 = l1.next
            l2 = l2.next
        while l1:
            new_node = ListNode()
            current_node.next = new_node
            current_node = new_node
            cal = carry + l1.val
            new_node.val = cal % 10
            carry = cal // 10
            l1 = l1.next
        while l2:
            new_node = ListNode()
            current_node.next = new_node
            current_node = new_node
            cal = carry + l2.val
            new_node.val = cal % 10
            carry = cal // 10
            l2 = l2.next
        if carry:
            new_node = ListNode()
            current_node.next = new_node
            new_node.val = carry
        return sentinel.next
    
# recursive
# class Solution:
#     def addTwoNumbers(self, l1: ListNode, l2: ListNode, c=0) -> ListNode:
#         val = l1.val + l2.val + c
#         c = val // 10
#         ret = ListNode(val % 10 ) 
        
#         if (l1.next != None or l2.next != None or c != 0):
#             if l1.next == None:
#                 l1.next = ListNode(0)
#             if l2.next == None:
#                 l2.next = ListNode(0)
#             ret.next = self.addTwoNumbers(l1.next,l2.next,c)
#         return ret
            