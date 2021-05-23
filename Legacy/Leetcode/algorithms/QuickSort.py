# quick sort in place O(1) space
import random
def partition(nums, p, r):
    x = nums[r]
    last_smaller = p - 1
    for i in range(p, r):
        if nums[i] <= x:
            last_smaller += 1
            nums[last_smaller], nums[i] = nums[i], nums[last_smaller]
    nums[last_smaller + 1], nums[r] = nums[r], nums[last_smaller + 1]
    return last_smaller + 1

def random_partition(nums, p, r):
    i = random.randint(p, r)
    nums[i], nums[r] = nums[r], nums[i]
    return partition(nums, p, r)

def quick_sort(nums, p, r):
    if p < r:
        q = partition(nums, p, r)
        quick_sort(nums, p, q-1)
        quick_sort(nums, q+1, r)

nums = [5, 13, 2, 25, 7, 17, 20, 8, 4]
quick_sort(nums,0, 8)
print nums