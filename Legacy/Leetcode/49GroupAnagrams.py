# Given an array of strings, group anagrams together.
#
# For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Return:
#
# [
#   ["ate", "eat","tea"],
#   ["nat","tan"],
#   ["bat"]
# ]

def group_anagrams(strs):
    big_dict = {}
    for string in strs:
        small_dict = {}
        for char in string:
            if char not in small_dict:
                small_dict[char] = 1
            else:
                small_dict[char] += 1
        key = frozenset(small_dict.items())
        if key not in big_dict:
            big_dict[key] = [string]
        else:
            big_dict[key].append(string)
    ans = []
    for key in big_dict:
        ans.append(big_dict[key])
    return ans

print group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"])