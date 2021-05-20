# Return number of substrings that contain all vowels "aeiou"

def find_substring(s):
    length = len(s)
    if length < 5:
        return 0
    vowels = set(['a','e','i','o','u'])
    ans = 0
    appear = set()
    for i in range(length):
        if s[i] in vowels:
            appear.add(s[i])
            if len(appear) == 5:
                ans += 1
        else:
            appear.clear()
    return ans

print(find_substring("aeoibsddaeiouudb"))