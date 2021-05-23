def count_and_say(n):
    if n == 1:
        return '1'
    else:
        res = ''
        base_on = count_and_say(n - 1)
        length = len(base_on)
        digit = base_on[0]
        count = 1
        if length == 1:
            res += str(count) + digit
            return res
        for i in range(1, length):
            if base_on[i] == digit:
                count += 1
            else:
                res += str(count) + digit
                count = 1
                digit = base_on[i]
        res += str(count) + digit
        return res

print count_and_say(4)