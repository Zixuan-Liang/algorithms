# Implement int sqrt(int x).
#
# Compute and return the square root of x.

def sqrt(x):
    start = 0
    end = x
    while start != end:
        mid = end - (end - start) / 2
        if (mid ** 2) < x:
            start = mid
        elif (mid ** 2) > x:
            end = mid - 1
        else:
            return mid
    return start

print sqrt(9)