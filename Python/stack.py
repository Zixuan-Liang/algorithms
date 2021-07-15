# Just use a list.

stack = []
stack.append(1)
stack.append(2)
stack.pop()
size = len(stack)
if size != 0:
    top = stack[-1]
    print(top)
