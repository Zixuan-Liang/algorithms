from typing import List
import heapq
# 算法复杂度 nlogk，n为所有节点的数量，k为链表的数量

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 自定义堆节点，存储值和索引，比较时只比较值
class HeapNode:
    def __init__(self, val, index):
        self.val = val
        self.index = index
    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = []
        k = len(lists)
        if k == 0: return None
        # 初始化最小堆，存储每个链表的头节点值和链表索引，如果链表为空，以无穷大表示它的节点值
        for i in range(k):
            if lists[i] == None:
                heapq.heappush(heap, HeapNode(float('inf'), i))
            else:
                heapq.heappush(heap, HeapNode(lists[i].val, i))
        # 哨兵节点，指向最后要返回的头节点
        dummy = ListNode()
        current = dummy
        # 一直进行出堆和入堆操作，直到堆顶的值为无穷大（意味着所有链表访问完毕）
        while heap[0].val != float('inf'):
            # 出堆，以堆顶值新建链表节点
            heapNode = heapq.heappop(heap)
            listNode = ListNode(heapNode.val)
            current.next = listNode
            current = listNode
            # 堆同时存储了堆顶节点对应的链表在输入数组中的索引，访问它，并指向下一个节点
            i = heapNode.index
            lists[i] = lists[i].next
            # 和25-28行类似
            if not lists[i]:
                heapq.heappush(heap, HeapNode(float('inf'), i))
            else:
                heapq.heappush(heap, HeapNode(lists[i].val, i))
        return dummy.next
                