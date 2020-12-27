from itertools import combinations
from collections import deque as Queue

def shortest_chain(names, queries):
    graph = [[0 for i in range(26)] for i in range(26)]
    for name in names:
        name = set(name)
        combs = combinations(name, 2)
        for comb in combs:
            idx1, idx2 = ord(comb[0]) - ord('A'), ord(comb[1]) - ord('A')
            graph[idx1][idx2] = 1 
            graph[idx2][idx1] = 1
    distance = [[-1 for i in range(26)] for i in range(26)]
    for i in range(26):
        distance[i][i] = 0
    for i in range(26):
        visited = [0 for _ in range(26)]
        visited[i] = 1
        queue = Queue()
        queue.append(i)
        while queue:
            u = queue.popleft()
            for v in range(26):
                if graph[u][v] == 1 and visited[v] == 0:
                    visited[v] = 1
                    distance[i][v] = distance[i][u] + 1
                    queue.append(v)
    ans = []
    for query in queries:
        name1, name2 = names[query[0]-1], names[query[1]-1]
        name1, name2 = set(name1), set(name2)
        min_dist = float('inf')
        for l1 in name1:
            l1 = ord(l1) - ord('A')
            for l2 in name2:
                l2 = ord(l2) - ord('A')
                if distance[l1][l2] != -1:
                    min_dist = min(min_dist, distance[l1][l2])
        if min_dist == float('inf'):
            ans.append(-1)
        else:
            ans.append(min_dist + 2)
    return ans

T = int(input())
for i in range(T):
    line = list(map(int, input().split()))
    N, Q = line[0], line[1]
    names = list(map(str, input().split()))
    queries = []
    for _ in range(Q):
        query = list(map(int, input().split()))
        queries.append(query)
    ans = shortest_chain(names, queries)
    print("Case #" + str(i+1) + ":", end=" ")
    print(" ".join(map(str, ans)))