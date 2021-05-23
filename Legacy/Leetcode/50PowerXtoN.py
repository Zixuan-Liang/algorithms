# Implement pow(x, n).

def pos_pow(x, n):
    if n == 0:
        return 1
    else:
        temp = my_pow(x, n/2)
        if n % 2 == 0:
            return temp * temp
        else:
            return temp * temp * x

def my_pow(x, n):
    if n >= 0:
        return pos_pow(x, n)
    else:
        return 1/pos_pow(x, abs(n))
