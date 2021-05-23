# this randomized algorithm selects the i smallest element in the list in expected linear time
# worst time is O(n^2)
import QuickSort
def random_select(nums, p, r, i):
    if p == r:
        return nums[p]
    q = QuickSort.random_partition(nums, p, r)
    k = q - p + 1
    if k == i:
        return nums[q]
    elif k < i:
        return random_select(nums, q+1, r, i-k)
    else:
        return random_select(nums, p, q-1, i)

print random_select([5, 13, 2, 25, 7, 17, 20, 8, 4], 0, 8, 4)
