# Divide two integers without using multiplication, division and mod operator. If it is overflow, return MAX_INT.

def divide(dividend, divisor):
    positive = (dividend < 0) is (divisor < 0)
    dividend, divisor = abs(dividend), abs(divisor)
    result = 0
    while dividend >= divisor:
        temp, i = divisor, 1
        while dividend >= temp:
            dividend -= temp
            result += i
            i <<= 1
            temp <<= 1
    if not positive:
        result = - result
    return min(max(-2147483648, result), 2147483647)

