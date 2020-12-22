from typing import List

class Solution:
    # O(n^2) solution
    # def subarraySum(self, nums: List[int], k: int) -> int:
    #     n = len(nums)
    #     if n == 0:
    #         return 0
    #     running = [0]
    #     for i in range(n):
    #         running.append(running[i] + nums[i])
    #     ans = 0
    #     for i in range(n):
    #         for j in range(i, n):
    #             if running[j+1] - running[i] == k:
    #                 ans += 1
    #     return ans
                
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