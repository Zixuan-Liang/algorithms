import random

def largest_continuous_sum(arr):
    if len(arr) == 0:
        return 0
    max_sum = arr[0]
    current_sum = arr[0]
    for num in arr[1:]:
        current_sum = max(current_sum+num, num)
        max_sum = max(max_sum, current_sum)
    return max_sum

def brute_force(arr):
    if len(arr) == 0:
        return 0
    max_sum = arr[0]
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            candidate = 0
            for k in range(i, j+1):
                candidate += arr[k]
            if candidate > max_sum:
                max_sum = candidate
    return max_sum

while True:
    arr = [random.randint(-100, 100) for i in range(10)]
    assert largest_continuous_sum(arr) == brute_force(arr)
    print("Test passed")