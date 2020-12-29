from typing import List
# Top-down DP
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort()
        N = len(coins)
        inf = float('inf')
        memo = [[-1 for i in range(amount+1)]for i in range(N+1)]
        def search(index, amount):
            if index >= N or amount < 0:
                return inf
            if memo[index][amount] != -1:
                return memo[index][amount]
            if amount == 0:
                memo[index][amount] = 0
            elif amount < coins[index]:
                memo[index][amount] = inf
            else:
                comb1 = search(index+1, amount)
                comb2 = search(index+1, amount-coins[index])+1
                comb3 = search(index, amount-coins[index])+1
                memo[index][amount] = min(comb1, comb2, comb3)
            return memo[index][amount]
        ans = search(0, amount)
        return ans if ans != inf else -1

# Bottom-up DP    
# class Solution:
#     def coinChange(self, coins: List[int], amount: int) -> int:
#         dp = [float('inf')] * (amount + 1)
#         dp[0] = 0
#         for coin in coins:
#             for x in range(coin, amount + 1):
#                 dp[x] = min(dp[x], dp[x - coin] + 1)
#         return dp[amount] if dp[amount] != float('inf') else -1 

# class Solution:
#     def coinChange(self, coins, amount):
#         level = seen = {0}
#         number = 0
#         while level:
#             if amount in level:
#                 return number
#             level = {a+c for a in level for c in coins if a+c <= amount} - seen
#             seen |= level
#             number += 1
#         return -1