# heap aka priority queue
# by default min heap, if max heap is needed, value * -1 before push

import heapq
heap = []
heapq.heappush(heap, 3)
heapq.heappush(heap, 1)
heapq.heappush(heap, 2)
print(heap[0])
heapq.heappop(heap)
print(heap[0])

x = [1,6,7,4,2,9]
heapq.heapify(x)
print(x)

print(heapq.nlargest(3, x))
print(heapq.nsmallest(3, x))
