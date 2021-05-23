# You are climbing a stair case. It takes n steps to reach to the top.
#
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
#
# Note: Given n will be a positive integer.

def climb_stairs(n):
    if n == 0 or n == 1:
        return 1
    else:
        table = [1, 1]
        for i in range(2, n+1):
            table.append(table[i - 2] + table[i - 1])
        return table[n]