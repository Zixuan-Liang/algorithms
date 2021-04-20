import collections

class Solution:
    def groupStrings(self, strings):
        
        table = collections.defaultdict(list)
        
        for string in strings:
            translate = '0'
            for i in range(1, len(string)):
                shift = ord(string[i]) - ord(string[i-1])
                if shift < 0:
                    shift = 26 + shift
                translate += str(shift)
            table[(len(string), translate)].append(string)

        return list(table.values())