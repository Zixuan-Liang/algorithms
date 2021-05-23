# merge nums list from index p to r, nums[p:q+1] and nums[q+1:r+1] are sorted respectively
import sys
def merge(nums, p, q, r):
    left, right = nums[p:q+1], nums[q+1:r+1]
    left.append(sys.maxint)
    right.append(sys.maxint)
    left_idx, right_idx = 0, 0
    for i in range(p, r+1):
        if left[left_idx] < right[right_idx]:
            nums[i] = left[left_idx]
            left_idx += 1
        else:
            nums[i] = right[right_idx]
            right_idx += 1
    print nums

merge([3,5,1,4,6],0,1,4)
