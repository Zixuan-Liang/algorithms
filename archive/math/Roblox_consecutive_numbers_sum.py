# N = (x + 1) + ... + (x + k)
# N = x k + k(k + 1)/2
import math

def consecutive_numbers_sum(N):
    count = 0
    upper_limit = math.ceil((2 * N + 0.25)**0.5 - 0.5) + 1
    for k in range(1, upper_limit):
        if (N - k * (k + 1) // 2) % k == 0:
            count += 1
    return count        

print(consecutive_numbers_sum(15))