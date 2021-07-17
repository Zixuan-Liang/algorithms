from typing import List

class Solution: 
        def subarraySum(self, nums: List[int], k: int) -> int:
            ans = 0
            n = len(nums)
            if n == 0:
                return ans
            table = {0: 1}
            running = 0
            for i in range(n):
                running += nums[i]
                residual = running - k
                if residual in table:
                    ans += table[residual]
                if running in table:
                    table[running] += 1
                else:
                    table[running] = 1
            return ans