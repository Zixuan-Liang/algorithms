class Solution:
    def longestOnes(self, A, K):
        res = 0
        zeroCount = 0
        left, right = 0, 0

        while right < len(A):
            # 取窗口右侧值
            ch = A[right]
            # 更新窗口内相关的数据
            if ch == 0:
                zeroCount += 1
            if zeroCount <= K:
                res = max(res, right-left+1)
            # 右移窗口
            right += 1
            # 判断是否需要左移窗口
            while zeroCount > K:
                # 取窗口左侧值
                ch = A[left]
                # 更新窗口内相关数据
                if ch == 0:
                    zeroCount -= 1
                # 左移窗口
                left += 1
        return res