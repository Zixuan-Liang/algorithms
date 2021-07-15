import random

class Solution:

    def __init__(self, nums: List[int]):
        self.origin = nums
        self.shuf = []
        
    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.origin

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        self.shuf = [n for n in self.origin]
        random.shuffle(self.shuf)
        return self.shuf


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()