class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        english = "abcdefghijklmnopqrstuvwxyz"
        table = dict(zip(order, english))
        for i in range(len(words) - 1):
            word1, word2 = "", ""
            for char in words[i]:
                word1 += table[char]
            for char in words[i+1]:
                word2 += table[char]
            if word1 > word2:
                return False
        return True