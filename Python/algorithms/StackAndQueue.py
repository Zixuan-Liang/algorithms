# in python list is a stack, list.append is push, list.pop is pop
from collections import deque
queue = deque()
stack = list()
queue.append(1)
queue.append(2)
queue.append(3)
print queue
print queue.popleft()
print queue.popleft()
print queue.popleft()
stack.append(1)
stack.append(2)
stack.append(3)
print stack
print stack.pop()
print stack.pop()
print stack.pop()