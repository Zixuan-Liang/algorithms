import heapq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        heap = []
        stations.append([target, 0])
        ans = 0
        prev = 0
        currFuel = startFuel
        for position, fuel in stations:
            currFuel -= (position - prev)
            while currFuel < 0 and len(heap) > 0:
                currFuel += -heapq.heappop(heap)
                ans += 1
            if currFuel < 0:
                return -1
            heapq.heappush(heap, -fuel)
            prev = position
        return ans
        