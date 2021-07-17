# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        n = len(nums)

        def helper(left, right):
            if left > right:
                return None
            if left == right:
                return TreeNode(nums[left])
            middle = left + (right - left) // 2
            root = TreeNode(nums[middle])
            root.left = helper(left, middle - 1)
            root.right = helper(middle+1, right)
            return root

        return helper(0, n-1)
