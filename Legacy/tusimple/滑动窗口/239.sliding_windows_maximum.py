from collections import deque as Queue

# 用单调队列解决滑动窗口问题
# 确保队列头是队列的最大值，这样可以在滑动的时候用O(1)时间取得窗口内的最大值
class Solution:
    def maxSlidingWindow(self, nums, k):
        queue = Queue()
        left, right = 0, k-1
        res = []
        # 先把前K-1个值放进窗口
        for i in range(k-1):
            while queue and queue[-1] < nums[i]:
                queue.pop()
            queue.append(nums[i])
        # 窗口右端从第K个数开始往右滑
        while right < len(nums):
            ch = nums[right]
            # 把队列尾小于窗口右端的值全部弹出，确保队列是单调的
            while queue and queue[-1] < ch:
                queue.pop()
            queue.append(ch)
            # 这样队列头就是窗口的最大值
            res.append(queue[0])
            right += 1
            # 窗口左移前，检查窗口左端值，如果该值等于队列头（最大值），那队列头也要弹出
            if nums[left] == queue[0]:
                queue.popleft()
            left += 1
        return res