# You are given two non-empty linked lists representing two non-negative integers.
# The digits are stored in reverse order and each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# l1 l2: listnode.val, listnode.next

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    def add(self, x):
        self.next = ListNode(x)

def add_two_num(l1, l2):
    root = l1
    this_node = l1
    that_node = l2
    carry = 0
    while this_node and that_node:
        summary = this_node.val + that_node.val + carry
        carry = summary / 10
        summary %= 10
        this_node.val = summary
        if not this_node.next and not that_node.next and carry:
            this_node.next = ListNode(carry)
            carry = 0
            this_node = this_node.next
            break
        elif not this_node.next and that_node.next:
            this_node.next = that_node.next
            this_node = that_node.next
            break
        elif this_node.next and not that_node.next:
            this_node = this_node.next
            break
        else:
            this_node = this_node.next
            that_node = that_node.next
    while this_node:
        summary = this_node.val + carry
        carry = summary / 10
        summary %= 10
        this_node.val = summary
        if not this_node.next:
            if carry:
                this_node.next = ListNode(carry)
                carry = 0
        this_node = this_node.next
    return root