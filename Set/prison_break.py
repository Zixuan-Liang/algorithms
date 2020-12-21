def find_longest_consecutive(bars):
    s = set()
    for bar in bars:
        s.add(bar)
    result = 0
    for i in range(len(bars)):
        if (bars[i] - 1) not in s:
            j = bars[i]
            while (j in s):
                j += 1
            result = max(result, j - bars[i])
    return result

def prison(n, m, h, v):
    hole_height = find_longest_consecutive(h) + 1
    hole_width = find_longest_consecutive(v) + 1
    return hole_height * hole_width

