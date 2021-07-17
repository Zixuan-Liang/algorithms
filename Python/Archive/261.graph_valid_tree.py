import collections

class Solution:
    def validTree(self, n, edges):
        
        if n == 1:
            return True

        neighbors = collections.defaultdict(list)
        for n1, n2 in edges:
            neighbors[n1].append(n2)
            neighbors[n2].append(n1)

        if len(neighbors) < n:
            return False

        seen = set()

        queue = collections.deque()
        queue.append(0)
        seen.add(0)

        while queue:
            for i in range(len(queue)):
                node = queue.popleft()
                visited = 0
                for neighbor in neighbors[node]:
                    if neighbor in seen:
                        visited += 1
                        if visited >= 2:
                            return False
                    else:
                        seen.add(neighbor)
                        queue.append(neighbor)

        return len(seen) == n
        