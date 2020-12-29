from typing import List
class Solution:
    def compress(self, chars: List[str]) -> int:
        previous = ''
        count = 1
        current = -1
        for char in chars:
            if char != previous:
                if count > 1:
                    count = str(count)
                    for i in range(len(count)):
                        current += 1
                        chars[current] = count[i]
                current += 1
                chars[current] = char
                count = 1
            else:
                count += 1
            previous = char
        if count > 1:
            count = str(count)
            for i in range(len(count)):
                current += 1
                chars[current] = count[i]
        return current + 1