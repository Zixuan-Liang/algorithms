class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        ans = []
        if len(intervals) == 0:
            return ans
        ans.append(intervals[0])
        if len(intervals) == 1:
            return ans
        for i in range(1, len(intervals)):
            inter = ans[-1]
            candidate = intervals[i]
            if candidate[0] > inter[1]:
                ans.append(candidate)
            else:
                ans[-1] = [inter[0], max(inter[1], candidate[1])]
        return ans