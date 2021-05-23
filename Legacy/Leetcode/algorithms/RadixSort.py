# radix sort is a sorting based on a stable sort such as counting sort so it is linear sort
# it needs O(n) space if we have limited memory we prefer in place sort like quick sort
def radix_sort(nums):
    digits = len(str(max(nums)))
    for i in range(digits):
        s = [[] for j in range(10)]
        for num in nums:
            index = num/(10**i)%10
            s[index].append(num)
        nums = [a for b in s for a in b] # remember this will create a new array!
    return nums

nums = [64,8,216,512,27,729,0,1,343,125]
print radix_sort(nums)