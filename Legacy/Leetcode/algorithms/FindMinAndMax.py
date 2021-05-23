# find both min and max in 3 * floor(n/2) operation times, because there are only 3 comparison in each iteration
def compute_new_min_max(min_num, max_num, pre_one, next_one):
    if pre_one > next_one:
        return min(next_one, min_num), max(pre_one, max_num)
    else:
        return min(pre_one, min_num), max(next_one, max_num)

def min_and_max(nums):
    length = len(nums)
    if length % 2 == 1:
        min_num = max_num = nums[0]
        for i in range(1, length, 2):
            min_num, max_num = compute_new_min_max(min_num, max_num, nums[i], nums[i+1])
    else:
        min_num = min(nums[0], nums[1])
        max_num = max(nums[0], nums[1])
        for i in range(2, length, 2):
            min_num, max_num = compute_new_min_max(min_num, max_num, nums[i], nums[i + 1])
    return min_num, max_num

print min_and_max([5, 13, 2, 25, 7, 17, 20, 8, 4])