import Merge
# merge sort nums[p:r+1]
def merge_sort(nums, p, r):
    if p < r:
        q = (p + r) / 2
        merge_sort(nums, p, q)
        merge_sort(nums, q+1, r)
        Merge.merge(nums, p, q, r)

merge_sort([4, 5, 1, 2, 8, 3, 0], 0, 6)
