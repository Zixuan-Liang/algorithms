class Solution:
    
    def findAllConcatenatedWordsInADict(self, words):
        self.words = set(words)
        if '' in self.words:
            self.words.remove('')
        self.minLen = float('inf')
        for word in words:
            self.minLen = min(self.minLen, len(word))
        ans = []
        for word in self.words:
            if self.helper(word, 0):
                ans.append(word)
        return ans
    
    def helper(self, word, start):
        for i in range(start+self.minLen, len(word)-self.minLen+1):
            if word[start:i] in self.words and (word[i:] in self.words or self.helper(word, i)):
                return True
        return False