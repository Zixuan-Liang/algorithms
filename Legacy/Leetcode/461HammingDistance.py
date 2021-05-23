# The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

def hamming_distance(x, y):
    z = x ^ y
    result = 0
    while z != 0:
        result += z & 1
        z = z >> 1
    return result

print hamming_distance(1, 4)