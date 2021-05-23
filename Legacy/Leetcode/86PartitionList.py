# Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
#
# You should preserve the original relative order of the nodes in each of the two partitions.
#
# For example,
# Given 1->4->3->2->5->2 and x = 3,
# return 1->2->2->4->3->5.




# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if head == None:
            return None
        if head.next == None:
            return head
        left_dummy = ListNode(0)
        right_dummy = ListNode(0)
        left_end = left_dummy
        right_end = right_dummy
        p = head
        while p != None:
            if p.val < x:
                left_end.next = p
                left_end = left_end.next
            else:
                right_end.next = p
                right_end = right_end.next
            p = p.next
        right_end.next = None
        left_end.next = right_dummy.next
        return left_dummy.next
