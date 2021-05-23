# Given an integer, convert it to a roman numeral.
def convert1(x):
    result = ''
    x %= 10
    if x == 9:
        return 'IX'
    elif x == 4:
        return 'IV'
    elif x >= 5 and x <= 8:
        result += 'V'
        for i in range(x - 5):
            result += 'I'
    else:
        for i in range(x):
            result += 'I'
    return result

def convert2(x):
    result = ''
    x %= 100
    if x >= 90:
        return 'XC'
    elif x >= 50:
        result += 'L'
        for i in range((x - 50) / 10):
            result += 'X'
    elif x >= 40:
        return 'XL'
    else:
        for i in range(x/10):
            result += 'X'
    return result

def convert3(x):
    result = ''
    x %= 1000
    if x >= 900:
        return 'CM'
    elif x >= 500:
        result += 'D'
        for i in range((x - 500) / 100):
            result += 'C'
    elif x >= 400:
        return 'CD'
    else:
        for i in range(x/100):
            result += 'C'
    return result

def convert4(x):
    result = ''
    M = x / 1000
    for i in range(M):
        result += 'M'
    return result

def int_to_roman(x):
    result = ''
    result += convert4(x) + convert3(x) + convert2(x) + convert1(x)
    return result