from typing import List

# Python uses Timsort (hybrid of merge sort and insert sort) so sorting is guaranteed to be stable
# So by default the oders of the digit logs can be preserved
class Solution:
    def sortHelper(self, string):
        _id, words = string.split(" ", maxsplit=1)
        return (0, words, _id) if words[0].isalpha() else (1, )
    
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        return sorted(logs, key=self.sortHelper)