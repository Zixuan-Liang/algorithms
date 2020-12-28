# This solution TLE

# from collections import deque as Queue

# class Solution:
#     def helper(self, x, y):
#         if len(x) == len(y):
#             diff = 0
#             i = 0
#             while i < len(x):
#                 if x[i] != y[i]:
#                     diff += 1
#                 i += 1
#             return diff == 1
#         else:
#             return False
    
#     def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
#         adjacent = {}
#         N = len(wordList)
#         for x in wordList:
#             adjacent[x] = []
#             for y in wordList:
#                 if self.helper(x, y):
#                     adjacent[x].append(y)
#         if endWord not in adjacent:
#             return 0
#         else:
#             visited, distance = {}, {}
#             for word in wordList:
#                 visited[word] = 0
#                 distance[word] = -1
#             visited[endWord] = 1
#             distance[endWord] = 0
#             queue = Queue()
#             queue.append(endWord)
#             while len(queue) != 0:
#                 u = queue.popleft()
#                 for v in adjacent[u]:
#                     if visited[v] == 0:
#                         visited[v] = 1
#                         distance[v] = distance[u] + 1
#                         queue.append(v)
#             ans = 3 * N
#             for u in distance:
#                 if distance[u] != -1:
#                     if self.helper(u, beginWord):
#                         ans = min(ans, distance[u]+2)
#                     elif u == beginWord:
#                         ans = min(ans, distance[u]+1)
#             return ans if ans <= N+1 else 0

from collections import deque as Queue, defaultdict

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        transform = defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                transform[word[:i]+'*'+word[i+1:]].append(word)
        visited = {}
        for word in wordList:
            visited[word] = 0
        visited[beginWord] = 1
        queue = Queue()
        queue.append((beginWord, 1))
        while len(queue) != 0:
            word, level = queue.popleft()
            for i in range(len(word)):
                if word[:i]+'*'+word[i+1:] in transform:
                    for x in transform[word[:i]+'*'+word[i+1:]]:
                        if x == endWord:
                            return level+1
                        if visited[x] == 0:
                            visited[x] = 1
                            queue.append((x, level+1))
        return 0