class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        seen = {}
        words = s.split()
        if len(pattern) != len(words):
            return False
        for i, ch in enumerate(pattern):
            if ch not in seen:
                seen[ch] = words[i]
            else:
                if seen[ch] != words[i]:
                    return False
        return len(seen) == len(set(seen.values()))