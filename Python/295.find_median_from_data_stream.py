# import heapq

# class MedianFinder:

#     def __init__(self):
#         """
#         initialize your data structure here.
#         """
#         self.counting = [0 for i in range(101)]
#         self.below = []
#         self.below_sorted = 1
#         self.above = []
#         self.above_sorted = 1
        
#         self.total = 0

#     def addNum(self, num: int) -> None:
#         self.total += 1
#         if num >= 0 and num <= 100:
#             self.counting[num] += 1
#         elif num < 0:
#             self.below.append(num)
#             self.below_sorted = 0
#         else:
#             self.above.append(num)
#             self.above_sorted = 0

#     def findMedian(self) -> float:
#         half = (self.total+1)//2
#         if len(self.below) >= half:
#             if not self.below_sorted:
#                 self.below.sort()
#                 self.below_sorted = 1
#             if self.total % 2 == 1:
#                 return self.below[half - 1]
#             else:
#                 if len(self.below) > half:
#                     return (self.below[half-1] + self.below[half]) / 2
#                 else:
#                     low = self.below[half - 1]
#                     i = 0
#                     while i<101 and self.counting[i]==0:
#                         i += 1
#                     if i < 101:
#                         return (low + i) / 2
#                     else:
#                         if not self.above_sorted:
#                             self.above.sort()
#                             self.above_sorted = 1
#                         high = self.above[0]
#                         return (low + high) / 2
#         elif len(self.above) >= half:
#             if not self.above_sorted:
#                 self.above.sort()
#                 self.above_sorted = 1
#             if self.total % 2 == 1:
#                 return self.above[-half]
#             else:
#                 if len(self.above) > half:
#                     return (self.above[-half] + self.above[-half-1]) / 2
#                 else:
#                     high = self.above[0]
#                     i = 100
#                     while i>=0 and self.counting[i]==0:
#                         i -= 1
#                     if i>= 0:
#                         return (i + high) / 2
#                     else:
#                         if not self.below_sorted:
#                             self.below.sort()
#                             self.below_sorted = 1
#                         low = self.below[-1]
#                         return (low + high) / 2
#         else:
#             residual = half - len(self.below)
#             i = 0
#             while i<101 and residual>self.counting[i]:
#                 residual -= self.counting[i]
#                 i += 1
#             if self.total % 2 == 1:
#                 return i
#             else:
#                 if residual == self.counting[i]:
#                     low = i
#                     j = i + 1
#                     while j<101 and self.counting[j]==0:
#                         j += 1
#                     high = j
#                     return (low + high) / 2
#                 else:
#                     return i
            
from heapq import *

class MedianFinder:

    def __init__(self):
        self.heaps = [], []

    def addNum(self, num):
        small, large = self.heaps
        heappush(small, -heappushpop(large, num))
        if len(large) < len(small):
            heappush(large, -heappop(small))

    def findMedian(self):
        small, large = self.heaps
        if len(large) > len(small):
            return float(large[0])
        return (large[0] - small[0]) / 2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()