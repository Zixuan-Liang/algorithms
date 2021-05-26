# build a max priority from a list based on max-heap
import HeapSort
def max_pri_queue(nums):
    HeapSort.build_max_heap(nums)

#operations on the priority queue
def max_ele(nums):
    return nums[0]

nums = [5, 13, 2, 25, 7, 17, 20, 8, 4]
max_pri_queue(nums)
print max_ele(nums)
