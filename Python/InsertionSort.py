# Insertion Sort
def insertion_sort(nums):
    length = len(nums)
    if not length or length == 1:
        return
    for i in range(1, length):
        key = nums[i]
        j = i - 1
        while j >= 0 and nums[j] > key:
            nums[j+1] = nums[j]
            j -= 1
        nums[j + 1] = key

