from collections import deque as Queue

class Solution:
    def slidingPuzzle(self, board):

        def neighbors(state):
            i = state.find('0')
            neighbors = [[1,3],[0,2,4],[1,5],[0,4],[1,3,5],[2,4]]
            for j in neighbors[i]:
                arr = list(state)
                arr[i], arr[j] = arr[j], arr[i]
                yield ''.join(arr)
        
        target = '123450'
        board = [[str(num) for num in row] for row in board]
        initial = ''.join(board[0]) + ''.join(board[1])
        queue = Queue([initial])
        seen = set([initial])

        res = 0
        while queue:
            for i in range(len(queue)):
                state = queue.popleft()
                if state == target:
                    return res
                else:
                    for newState in neighbors(state):
                        if newState not in seen:
                            queue.append(newState)
                            seen.add(newState)
            res += 1
        return -1
        
                
