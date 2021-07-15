import sys
# find maximum subarry across left array and right array
def max_cross_subarray(nums, p, q, r):
    max_left_sum = -sys.maxint
    left_sum = 0
    for i in range(q,-1,-1):
        left_sum += nums[i]
        if left_sum > max_left_sum:
            max_left_sum = left_sum
            low = i
    max_right_sum = -sys.maxint
    righ_sum = 0
    for i in range(q+1, r+1):
        righ_sum += nums[i]
        if righ_sum > max_right_sum:
            max_right_sum = righ_sum
            high = i
    return low, high, max_left_sum + max_right_sum

# find maximum subarray in nums[p:r+1], return low index and high index and sum
def max_subarray(nums, p, r):
    if p == r:
        return (p, r, nums[p])
    q = (p + r) / 2
    left = (left_low, left_high, left_sum) = max_subarray(nums, p, q)
    right = (right_low, right_high, right_sum) = max_subarray(nums, q+1, r)
    cross = (cross_low, cross_high, cross_sum) = max_cross_subarray(nums, p, q, r)
    if left_sum >= right_sum and left_sum >= cross_sum:
        return left
    elif right_sum >= cross_sum:
        return right
    else:
        return cross

print max_subarray([13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7], 0, 15)