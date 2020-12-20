from collections import deque as Queue

queue = Queue()

queue.append(1)
queue.append(2)
queue.append(3)

print(queue.popleft())
print(queue[0])

print(len(queue))