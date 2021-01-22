from typing import List

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        length = len(startTime)
        times = [[0, 0, 0] for _ in range(length)]
        for i in range(length):
            times[i][0] = startTime[i]
            times[i][1] = endTime[i]
            times[i][2] = profit[i]
        times.sort() # 排序
                
        dp = [0 for i in range(length)]
        
        res = 0
        s = 0
        pos = 0 # 标记位置
        for i in range(length):
            for j in range(pos, i):
                # 区间不重合
                if times[i][0] >= times[j][1]:
                    # 移动 pos 的位置
                    if j == pos:
                        pos += 1
                    s = max(s, dp[j])
             
            dp[i] = s + times[i][2]
            res = max(res, dp[i])
                              
        return res

# class Solution:
#     def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
#         H = sorted(zip(startTime, itertools.repeat(1), endTime, profit))
#         res = 0
#         while H:
#             t = heapq.heappop(H)
#             if t[1]:
#                 heapq.heappush(H, (t[2], 0, res + t[3]))
#             else:
#                 res = max(res, t[2])
#         return res

# def jobScheduling(self, startTime, endTime, profit):
#     jobs = sorted(zip(startTime, endTime, profit), key=lambda v: v[1])
#     dp = [[0, 0]]
#     for s, e, p in jobs:
#         i = bisect.bisect(dp, [s + 1]) - 1
#         if dp[i][1] + p > dp[-1][1]:
#             dp.append([e, dp[i][1] + p])
#     return dp[-1][1]