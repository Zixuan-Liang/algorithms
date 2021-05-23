# Write a function to find the longest common prefix string amongst an array of strings.
def long_com_pre(strs):
    if len(strs) == 0:
        return ""
    elif len(strs) == 1:
        return strs[0]
    elif len(strs) == 2:
        result = ''
        len1 = len(strs[0])
        len2 = len(strs[1])
        min_len = min(len1, len2)
        for i in range(min_len):
            if strs[0][i] != strs[1][i]:
                break
            else:
                result += strs[0][i]
        return result
    else:
        left = strs[:len(strs)/2]
        right = strs[len(strs)/2:]
        return long_com_pre([long_com_pre(left), long_com_pre(right)])