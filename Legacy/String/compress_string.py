# Example: AAAABBBBCCCCCDDEEEE becomes A4B4C5D2E4
import random

def compress_string(string):
    ans = ""
    previous = ""
    count = 1
    for char in string:
        if char != previous:
            if count > 1:
                ans += str(count)
            ans += char
            count = 1
        else:
            count += 1
        previous = char
    if count > 1:
        ans += str(count)
    return ans

def compress_string_2(string):
    char_arr = [""]
    count_arr = []
    ans = ""
    i = 0
    count = 1
    for char in string:
        if char != char_arr[i]:
            char_arr.append(char)
            count_arr.append(count)
            count = 1
            i += 1
        else:
            count += 1
    count_arr.append(count)
    for i in range(1, len(char_arr)):
        ans += char_arr[i]
        if count_arr[i] > 1:
            ans += str(count_arr[i])
    return ans

while True:
    string = ""
    for i in range(20):
        string += chr(ord("A") + random.randint(0, 25))
    assert compress_string(string) == compress_string_2(string)
    print("Test passed")