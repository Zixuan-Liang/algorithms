class Solution:
    def knightDialer(self, n):
        transfer = {}
        arr = [[4,6],[6,8],[7,9],[4,8],[3,9,0],[],[1,7,0],[2,6],[1,3],[2,4]]
        for i in range(10):
            transfer[i] = arr[i]

        memo = {}

        def helper(i, n):
            if (i, n) in memo:
                return memo[(i, n)]
            if n == 1:
                return 1
            else:
                ans = 0
                for j in transfer[i]:
                    ans += helper(j, n-1)
                memo[(i, n)] = ans
                return ans

        res = 0
        for i in range(10):
            res += helper(i, n)
        return res
                

    

        
