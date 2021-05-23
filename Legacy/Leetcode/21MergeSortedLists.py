# Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
#
# Subscribe to see which companies asked this question.

def mergeTwoLists(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    dummy = cur = ListNode(0)
    while l1 and l2:
        if l1.val < l2.val:
            cur.next = l1
            l1 = l1.next
        else:
            cur.next = l2
            l2 = l2.next
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next