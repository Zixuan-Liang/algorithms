# count sort is a kind of linear time complexity sorting, number in the list is in range 0 to k, it is O(k+n) so O(n)
def counting_sort(nums, k):
    count = [0] * k
    for num in nums:
        count[num] += 1
    for i in range(1,k):
        count[i] += count[i-1]
    result = [0] * len(nums)
    for num in nums:
        if count[num] > 0:
            result[count[num] - 1] = num
            count[num] -= 1
    return result

print counting_sort([5, 13, 2, 25, 7, 17, 20, 8, 4], 30)