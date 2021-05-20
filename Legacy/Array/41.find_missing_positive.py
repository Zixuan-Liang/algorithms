class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 0:
            return 1
        i = 0
        while i < N:
            if nums[i] == i+1:
                i += 1
            else:
                if nums[i] <= 0 or nums[i] > N:
                    nums[i] = 0
                    i += 1
                else:
                    if nums[nums[i]-1] == nums[i]:
                        nums[i] = 0
                        i += 1
                    else:        
                        nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        i = 0
        while i < N:
            if nums[i] != i+1:
                return i+1
            i += 1
        return N+1
                