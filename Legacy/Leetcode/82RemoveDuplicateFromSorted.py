# Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
#
# For example,
# Given 1->2->3->3->4->4->5, return 1->2->5.
# Given 1->1->1->2->3, return 2->3.

de# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        if head.next == None:
            return head
        dummy = ListNode(1)
        dummy.next = head
        previous = dummy
        start = head
        end = head
        while start != None and end != None:
            while end != None and start.val == end.val:
                end = end.next
            if start.next == end:
                previous = start
            else:
                previous.next = end
            start = end
        return dummy.next

