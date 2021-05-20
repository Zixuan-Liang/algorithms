# Definition for singly-linked list.

# 用优先队列实现

# 用lambda注入重写__lt__比较函数
ListNode.__lt__ = lambda self, other: self.val < other.val

import heapq

class Solution:
    def mergeKLists(self, lists):
        heap = []
        for node in lists:
            if node:
                heapq.heappush(heap, node)
        head = ListNode()
        tail = head
        while heap:
            f = heapq.heappop(heap)
            tail.next = f
            tail = tail.next
            if f.next:
                heapq.heappush(heap, f.next)
        return head.next

# 可以用一个counter避免比较node，因为node本身non-comparable

class Solution:
    def mergeKLists(self, lists):
        heap = []
        counter = 0
        for node in lists:
            if node:
                counter += 1
                heapq.heappush(heap, (node.val, counter, node))
        head = ListNode()
        tail = head
        while heap:
            f = heapq.heappop(heap)[2]
            tail.next = f
            tail = tail.next
            if f.next:
                counter += 1
                heapq.heappush(heap, (f.next.val, counter, f.next))
        return head.next


# 一个更严谨的实现两个node的比较

class PriorityQueueBucket:
    def __init__(self, key, value):
        self.key = key
        self.value = value
     
    def __lt__(self, other):
        return self.key < other.key
 
# 支持自定义comparator的PriorityQueue
class PriorityQueue:
    import heapq
    import functools
     
    def __init__(self, cmp = lambda x, y: x > y):
        self.container = []
        self.getKey = functools.cmp_to_key(
            lambda x, y: -1 if cmp(x, y) else 1 if cmp(y, x) else 0)
 
    def __len__(self):
        return len(self.container)
 
    def push(self, item):
        heapq.heappush(self.container, PriorityQueueBucket(self.getKey(item), item))
 
    def pop(self):
        return heapq.heappop(self.container).value
 
 
class Solution:
    # merge every two lists
 
    # priority queue
    # time Onlog(len(lists))
    # space Olen(lists) + n
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummy = ListNode(0)
        node = dummy
        n = len(lists)
        minHeap = PriorityQueue(lambda x, y: x.val < y.val)
        for l in lists:
            if l:
                minHeap.push(l)
        while minHeap:
            top = minHeap.pop()
            node.next = top
            node = node.next
            if top.next:
                minHeap.push(top.next)
        return dummy.next