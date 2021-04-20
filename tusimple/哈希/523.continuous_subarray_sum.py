class Solution:
    def checkSubarraySum(self, nums, k):
        running = 0
        # key: 余数，value：前缀和取余为key的下标
        # 一开始，取余为0的下标就是-1，不取任何数字
        table = {0: - 1}
        for i in range(len(nums)):
            running += nums[i]
            if k != 0:
                running %= k
            if running in table:
                if i - table[running] > 1:
                    return True
            else:
                table[running] = i
        return False

# 设位置 j < i : 
# 0 到 j 的前缀和 preSum1 = 某常数1 * k + 余数1
# 0 到 i 的前缀和 preSum2 = 某常数2 * k + 余数2
# 当找到 余数1 等于 余数2时， 则 j + 1 到 i 的连续和 = preSum2 - preSum1 = (某常数2 - 某常数1) * k， 必为 k 的倍数， 返回true