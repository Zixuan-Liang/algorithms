def beautiful_subarrays(arr, m):
    consecutive_even = 0
    consecutive_evens = []
    odd_count = 0
    for num in arr:
        if num % 2 == 0:
            consecutive_even += 1
        else:
            consecutive_evens.append(consecutive_even)
            consecutive_even = 0
            odd_count += 1
    consecutive_evens.append(consecutive_even)
    ans = 0
    for i in range(odd_count - m + 1):
        ans += (consecutive_evens[i]+1) * (consecutive_evens[i+m]+1)
    return ans

print(beautiful_subarrays([1,2,3,4,5], 2))
    