# The problem description is misleading, basically, the following schedule is not allowed:

# ----111111
# 000000----

# It must be like this:

# ---1111---
# --000000--


class Solution:
    
    def exclusiveTime(self, N, logs):
        ans = [0] * N
        stack = []
        prev_time = 0

        for log in logs:
            fn, typ, time = log.split(':')
            fn, time = int(fn), int(time)

            if typ == 'start':
                if stack:
                    ans[stack[-1]] += time - prev_time 
                stack.append(fn)
                prev_time = time
            else:
                ans[stack.pop()] += time - prev_time + 1
                prev_time = time + 1

        return ans