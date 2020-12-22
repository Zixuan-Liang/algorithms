from typing import List
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        heap = []
        for point in points:
            distance = point[0] ** 2 + point[1] ** 2
            heapq.heappush(heap, (distance, point))
        ans = []
        for i in range(K):
            ans.append(heapq.heappop(heap)[1])
        return ans