# heap sort run time: worst case: nlgn, expceted: --- We use max-heap in heap sort
def left(i):
    return (i + 1) * 2 - 1


def right(i):
    return (i + 1) * 2


# max-heapify, O(lgn), assume left and right of node i is already max-heap, maintain heap property
def max_heapify(nums, i, heap_size):
    left_node = left(i)
    right_node = right(i)
    largest = i
    if left_node < heap_size and nums[left_node] > nums[i]:
        largest = left_node
    if right_node < heap_size and nums[right_node] > nums[largest]:
        largest = right_node
    if largest != i:
        nums[i], nums[largest] = nums[largest], nums[i]
        max_heapify(nums, largest, heap_size)

# build max-heap in a list, floor(n/2) to (n-1) nodes are leaf nodes, it seems nlgn, but closer look it is O(n)
def build_max_heap(nums):
    for i in range(len(nums) / 2 - 1, -1, -1):
        max_heapify(nums, i, len(nums))

def heap_sort(nums):
    build_max_heap(nums)
    length = len(nums)
    heap_size = length
    for i in range(length-1, 0, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heap_size -= 1
        max_heapify(nums, 0, heap_size)
    print nums

heap_sort([5, 13, 2, 25, 7, 17, 20, 8, 4])
