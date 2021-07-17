class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            climbs = [1, 2]
            for i in range(2, n):
                climb = climbs[i-2] + climbs[i-1]
                climbs.append(climb)
            return climbs[-1]