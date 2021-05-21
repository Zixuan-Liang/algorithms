from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        index, check = 0, True
        while check and index < len(strs[0]):
            c = strs[0][index]
            for i in range(1, len(strs)):
                check = index < len(strs[i]) and strs[i][index] == c
                if not check: break
            if check: index += 1
        return strs[0][:index]