# Given a linked list, remove the nth node from the end of list and return its head.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def remove_nth_from_end(head, n):
    fast = slow = head
    for _ in range(n):
        fast = fast.next
    if not fast:
        return head.next
    while fast.next:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return head