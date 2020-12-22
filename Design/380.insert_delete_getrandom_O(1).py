import random

class RandomizedSet(object):

    def __init__(self):
        self.nums = []
        self.pos = {}
        
    def insert(self, val):
        check = val not in self.pos
        if check:
            self.nums.append(val)
            self.pos[val] = len(self.nums) - 1
        return check
        

    def remove(self, val):
        check = val in self.pos
        if check:
            index, last = self.pos[val], self.nums[-1]
            self.nums[index], self.pos[last] = last, index
            self.nums.pop()
            self.pos.pop(val)
        return check
            
    def getRandom(self):
        return random.choice(self.nums) # random.choice should be O(log n)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()