# Reverse digits of an integer.
# Example1: x = 123, return 321
# Example2: x = -123, return -321
def reverse_int(x):
    negative = (x < 0)
    string = str(x)
    if negative:
        string = string[1:]
    length = len(string)
    reverse = string[::-1]
    if length > 10 and string[10:] > '0' * (length - 10):
        return 0
    elif length == 10 and reverse >= '2147483648':
        return 0
    else:
        if negative:
            return - int(reverse)
        else:
            return int(reverse)

