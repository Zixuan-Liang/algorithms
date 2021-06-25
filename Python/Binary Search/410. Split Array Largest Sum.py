class Solution:
    
    def canSplit(self, nums, largestSum, m):
        subarrays = 1
        currSum = 0
        for n in nums:
            if n > largestSum:
                return False
            elif currSum + n <= largestSum:
                currSum += n
            else:
                currSum = n
                subarrays += 1
                if subarrays > m:
                    return False
        return True
    
    def splitArray(self, nums: List[int], m: int) -> int:
        low = 0
        high = 1000000001
        while low < high:
            mid = low + (high - low) // 2
            if self.canSplit(nums, mid, m):
                high = mid
            else:
                low = mid + 1
        return low