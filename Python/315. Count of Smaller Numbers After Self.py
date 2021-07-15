class Solution:
    
    def update(self, index, val, tree, size):
        index += size
        tree[index] += val
        while index > 1:
            index = index // 2
            tree[index] = tree[index * 2] + tree[index * 2 + 1]
    
    def query(self, left, right, tree, size):
        ans = 0
        left += size
        right += size
        while left < right:
            if left % 2 == 1:
                ans += tree[left]
                left += 1
            left = left // 2
            if right % 2 == 1:
                right -= 1
                ans += tree[right]
            right = right // 2
        return ans
    
    def countSmaller(self, nums):
        offset = 10000
        size = 20001
        tree = [0] * (size * 2)
        ans = []
        for i in range(len(nums)-1, -1, -1):
            ans.append(self.query(0, nums[i] + offset, tree, size))
            self.update(nums[i] + offset, 1, tree, size)
        return ans[::-1]