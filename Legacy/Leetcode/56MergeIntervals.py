# Given a collection of intervals, merge all overlapping intervals.
#
# For example,
# Given [1,3],[2,6],[8,10],[15,18],
# return [1,6],[8,10],[15,18].

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(lambda a,b:a.start - b.start)
        length = len(intervals)
        ans = []
        if length == 0:
            return ans
        ans = [intervals[0]]
        if length == 1:
            return ans
        for i in range(1, length):
            last_inter = ans[-1]
            if intervals[i].start > last_inter.end:
                ans.append(intervals[i])
            elif intervals[i].end <= last_inter.end:
                continue
            else:
                ans[-1] = Interval(last_inter.start, intervals[i].end)
        return ans