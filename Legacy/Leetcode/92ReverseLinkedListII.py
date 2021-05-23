# Reverse a linked list from position m to n. Do it in-place and in one-pass.
#
# For example:
# Given 1->2->3->4->5->NULL, m = 2 and n = 4,
#
# return 1->4->3->2->5->NULL.
#
# Note:
# Given m, n satisfy the following condition:
# 1 ≤ m ≤ n ≤ length of list.
#

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m == n:
            return head
        dummy = ListNode(0)
        dummy.next = head
        previous = dummy
        for i in range(m - 1):
            previous = previous.next
        start = previous.next
        first = previous.next
        second = first.next
        for i in range(n - m):
            temp = ListNode(second.val)
            temp.next = second.next
            second.next = first
            first = second
            second = temp.next
        previous.next = first
        start.next = second
        return dummy.next
