# By listing and labeling all of the permutations in order,
# We get the following sequence (ie, for n = 3):
#
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
# Given n and k, return the kth permutation sequence.
#
# Note: Given n will be between 1 and 9 inclusive.

def get_permutation(n, k):
    not_taken = [True for _ in range(n)]
    index = k - 1
    table = [1]
    for i in range(1, n):
        table.append(table[-1] * i)
    ans = ''
    for i in range(n, 0, -1):
        pos_in_rest = index / table[i - 1] + 1
        index = index % table[i - 1]
        total = 0
        for i in range(n):
            total += not_taken[i]
            if total == pos_in_rest:
                ans += str(i + 1)
                not_taken[i] = False
                break
    return ans

print get_permutation(9, 5)