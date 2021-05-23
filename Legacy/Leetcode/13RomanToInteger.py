# Given a roman numeral, convert it to an integer.
def isNegative(x, i):
    if i + 1 >= len(x):
        return -1
    elif x[i] == 'C' and (x[i+1] == 'D' or x[i+1] == 'M'):
        return 1
    elif x[i] == 'X' and (x[i+1] == 'L' or x[i+1] == 'C'):
        return 1
    elif x[i] == 'I' and (x[i+1] == 'V' or x[i+1] == 'X'):
        return 1
    else:
        return -1

def roman_to_int(x):
    result = 0
    length = len(x)
    for i in range(length):
        if x[i] == 'M':
            result += 1000
        elif x[i] == 'D':
            result += 500
        elif x[i] == 'C':
            result -= 100 * isNegative(x, i)
        elif x[i] == 'L':
            result += 50
        elif x[i] == 'X':
            result -= 10 * isNegative(x, i)
        elif x[i] == 'V':
            result += 5
        else:
            result -= isNegative(x, i)
    return result

print roman_to_int("DCXXI")