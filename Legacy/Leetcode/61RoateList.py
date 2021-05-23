# Given a list, rotate the list to the right by k places, where k is non-negative.
#
# For example:
# Given 1->2->3->4->5->NULL and k = 2,
# return 4->5->1->2->3->NULL.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        start = head
        end = head
        p = head
        length = 0
        while p != None:
            length += 1
            p = p.next
        if length == 0:
            return None
        num = k % length
        if num == 0:
            return head
        while end.next != None and num > 0:
            end = end.next
            num -= 1
        while end.next != None:
            end = end.next
            start = start.next
        end.next = head
        head = start.next
        start.next = None
        return head