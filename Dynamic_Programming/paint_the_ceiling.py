# s[i]: s[i]=((k*s[i-1]+b) mod m)+1+s[i-1])

def variants_count(n, s0, k, b, m, a):
    s = [s0]
    for i in range(n - 1):
        num = ((k * s[i] + b) % m) + 1 + s[i]
        s.append(num)
    count = 0
    row = n - 1
    col = 0
    while (row > col):
        if(s[row] * s[col] > a):
            count += col
            row -= 1
        else:
            col += 1
    return 2 * count + (row+1) * (col+1) - (s[row] * s[col] > a)

print(variants_count(3, 2, 3, 3, 2, 15))
print(variants_count(3, 1, 1, 1, 2, 4))

