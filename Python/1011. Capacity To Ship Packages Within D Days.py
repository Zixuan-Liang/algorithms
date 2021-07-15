class Solution:
    
    def canShip(self, weights, capacity, daysLimit):
        days = 1
        load = 0
        for weight in weights:
            if weight > capacity:
                return False
            elif load + weight <= capacity:
                load += weight
            else:
                load = weight
                days += 1
                if days > daysLimit:
                    return False
        return True
    
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low = 1
        high = 25000000
        while low < high:
            mid = low + (high - low) // 2
            if self.canShip(weights, mid, days):
                high = mid
            else:
                low = mid + 1
        return low