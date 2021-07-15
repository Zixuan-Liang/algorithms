import numpy as np
def hire(candidate):
    print 'hire candidate ', candidate

# build hire algorithm as same as assuming candidates occur randomly
def random_hire(nums):
    nums = list(np.random.permutation(nums))
    best = 0
    for i in range(len(nums)):
        if nums[i] > nums[best]:
            best = i
            hire(nums[i])

random_hire([1,2,3,4,5,6,7,8,9])