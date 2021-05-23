# Selection Sort
def selection_sort(nums):
    length = len(nums)
    if not length or length == 1:
        print nums
        return
    for i in range(length):
        min_idx = i
        for j in range(i+1, length):
            if nums[j] < nums[min_idx]:
                min_idx = j
        nums[i], nums[min_idx] = nums[min_idx], nums[i]
    print nums

selection_sort([1])
selection_sort([2,1])
selection_sort([3,2,4,1])