from collections import OrderedDict

def maximum_occurring_character(string):
    d = OrderedDict()
    for s in string:
        if s in d:
            d[s] += 1
        else:
            d[s] = 1
    m = 0
    c = ''
    for s in d:
        if d[s] > m:
            m = d[s]
            c = s
    return c

print(maximum_occurring_character("hello, world"))