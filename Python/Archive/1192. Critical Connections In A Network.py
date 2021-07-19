# Tarjan's algorithm
# import collections
# class Solution:
#     def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
#         self.num = 0
#         graph = collections.defaultdict(list)
#         for u, v in connections:
#             graph[u].append(v)
#             graph[v].append(u)
            
#         dfs_num, dfs_low = [None]*n, [None]*n
        
#         def dfs(node, parent):
#             # already visited
#             if dfs_num[node] is not None:return 
#             dfs_num[node] = dfs_low[node] = self.num
#             self.num += 1
#             for neighbor in graph[node]:
#                 if dfs_num[neighbor] is None:
#                     dfs(neighbor, node)
            
#             # minimal num in the neignbors, exclude the parent
#             dfs_low[node] = min([dfs_num[node]] + [dfs_low[neighbor] for neighbor in graph[node] if neighbor != parent])   
        
#         dfs(0, None)
        
#         res = []
#         #print(dfs_num)
#         #print(dfs_low)
#         for u, v in connections:
#             # non bridge
#             if dfs_low[u] > dfs_num[v] or dfs_low[v] > dfs_num[u]:
#                 res.append([u, v])
#         return res
    
import collections
class Solution(object):
    def criticalConnections(self, n, connections):
        def makeGraph(connections):
            graph = collections.defaultdict(list)
            for conn in connections:
                graph[conn[0]].append(conn[1])
                graph[conn[1]].append(conn[0])
            return graph

        graph = makeGraph(connections)
        connections = set(map(tuple, (map(sorted, connections))))
        rank = [-2] * n

        def dfs(node, depth):
            if rank[node] >= 0:
                # visiting (0<=rank<n), or visited (rank=n)
                return rank[node]
            rank[node] = depth
            min_back_depth = n
            for neighbor in graph[node]:
                if rank[neighbor] == depth - 1:
                    continue  # don't immmediately go back to parent. that's why i didn't choose -1 as the special value, in case depth==0.
                back_depth = dfs(neighbor, depth + 1)
                if back_depth <= depth:
                    connections.discard(tuple(sorted((node, neighbor))))
                min_back_depth = min(min_back_depth, back_depth)
            # rank[node] = n  # this line is not necessary. see the "brain teaser" section below
            return min_back_depth
            
        dfs(0, 0)  # since this is a connected graph, we don't have to loop over all nodes.
        return list(connections)