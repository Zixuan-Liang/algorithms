# bucket sort for list that falls into a range 0 to 1 evenly
import InsertionSort
import math
def bucket_sort(nums):
    n = len(nums)
    B = [[] for i in range(n)]
    for num in nums:
        B[int(math.floor(n * num))].append(num)
    for i in range(n):
        InsertionSort.insertion_sort(B[i])
    result = []
    for i in range(n):
        result += B[i]
    return result

print bucket_sort([0.79, 0.13, 0.16, 0.64, 0.39, 0.20, 0.89, 0.53, 0.71, 0.42])