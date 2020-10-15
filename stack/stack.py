from queue import LifoQueue

# stack = LifoQueue(maxsize = n)
# stack.put_nowait(item)
# stack.get_nowait()

stack = LifoQueue()
print(stack.qsize())
stack.put(1)
stack.put('a')
while (not stack.empty()):
    print(stack.get())
print(stack.full())

# from collections import deque

# stack = deque()

# stack.append(1)
# stack.append('a')
# stack.append([1,2,3])
# stack.appendleft((1,2))

# stack.reverse()

# stack.rotate(1)

# print(stack.count(1))

# stack.remove(1)

# while(stack):
#     print(stack.pop())

# stack.append({1:2})

# print(stack)

# stack.clear()

# print(stack)

# print(stack.maxlen)