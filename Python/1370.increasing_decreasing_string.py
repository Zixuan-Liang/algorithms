from collections import defaultdict
class Solution:
    def sortString(self, s: str) -> str:
        table = defaultdict(int)
        for letter in s:
            table[letter] += 1
        keys0 = list(table.keys())
        keys0.sort()
        keys1 = keys0[::-1]
        length = len(s)
        res = ""
        order = 0
        while len(res) < length:
            if order == 0:
                for key in keys0:
                    table[key] -= 1
                    if table[key] >= 0:
                        res += key
                order = 1
            else:
                for key in keys1:
                    table[key] -= 1
                    if table[key] >= 0:
                        res += key
                order = 0
        return res