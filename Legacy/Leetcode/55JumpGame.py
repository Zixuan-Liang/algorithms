# Given an array of non-negative integers, you are initially positioned at the first index of the array.
#
# Each element in the array represents your maximum jump length at that position.
#
# Determine if you are able to reach the last index.
#
# For example:
# A = [2,3,1,1,4], return true.
#
# A = [3,2,1,0,4], return false.

def can_jump(nums):
    length = len(nums)
    if length == 0 or length == 1:
        return True
    pos_of_zero = []
    nums[-1] = 1
    i = 0
    while i <= length - 2:
        if nums[i] == 0:
            start = i
            end = i
            while nums[end] == 0 and end <= length - 2:
                end += 1
            end -= 1
            pos_of_zero.append([start,end])
            i = end + 1
        else:
            i += 1
    if not pos_of_zero:
        return True
    last_zero_pos = -1
    max_can_reach = -1
    for pos in pos_of_zero:
        running_pos = last_zero_pos + 1
        last_zero_pos = pos[1]
        flag = False
        while running_pos < pos[0]:
            can_reach = running_pos + nums[running_pos]
            if can_reach > pos[1]:
                flag = True
                if can_reach > max_can_reach:
                    max_can_reach = can_reach
                running_pos += 1
            else:
                running_pos += 1
        if flag == False and max_can_reach <= pos[1]:
            return False
        if pos == pos_of_zero[-1]:
            return True


#print can_jump([3,2,1,0,4])
#print can_jump([3,0,0,0])
#print can_jump([2,0,1,1,2,1,0,0,0])
print can_jump([8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5])