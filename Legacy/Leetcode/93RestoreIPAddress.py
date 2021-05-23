def startWithZero(s):
    if s == '0':
        return False
    length = len(s)
    for i in range(length):
        if s[i] != '0':
            break
    if i == 0:
        return False
    else:
        return True


def search(s, n, result, candidate):
    if n == 0 and s != '':
        return
    elif len(s) < n:
        return
    elif n == 0 and s == '':
        result.append(candidate[:-1])
        return
    elif n == 1 and len(s) == 1:
        result.append(candidate + s[0])
        return
    elif n == 2 and len(s) == 2:
        result.append(candidate + s[0] + '.' + s[1])
        return
    elif n == 3 and len(s) == 3:
        result.append(candidate + s[0] + '.' + s[1] + '.' + s[2])
        return
    elif n == 4 and len(s) == 4:
        result.append(candidate + s[0] + '.' + s[1] + '.' + s[2] + '.' + s[3])
    else:
        search(s[1:], n - 1, result, candidate + s[0] + '.')
        if len(s) >= 2 and not startWithZero(s[0:2]):
            search(s[2:], n - 1, result, candidate + s[0:2] + '.')
        if len(s) >= 3 and s[0:3] <= '255' and not startWithZero(s[0:3]):
            search(s[3:], n - 1, result, candidate + s[0:3] + '.')


def restoreIpAddresses(s):
    """
    :type s: str
    :rtype: List[str]
    """
    ans = []
    candidate = ''
    search(s, 4, ans, candidate)
    return ans

print restoreIpAddresses("010010")