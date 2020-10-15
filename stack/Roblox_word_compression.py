# Given a string ‘str’ and an integer ‘k’, the task is to reduce the string by applying the following operation:
# Choose a group of ‘k’ consecutive identical characters and remove them. The operation can be performed any number of times until it is no longer possible.

from queue import LifoQueue
from collections import namedtuple

def word_compression(string, k):
    stack = LifoQueue()
    Record = namedtuple("Record", "character freq")
    for s in string:
        new_record = Record(character = s, freq = 1)
        if(stack.empty()):
            stack.put(new_record)
        else:
            top = stack.get()
            if top.character == s:
                if top.freq == k - 1:
                    for i in range(k - 2):
                        stack.get()
                else:
                    stack.put(top)
                    stack.put(Record(character = s, freq = top.freq + 1))
            else:
                stack.put(top)
                stack.put(new_record)
    result = ""
    while (not stack.empty()):
        result = stack.get().character + result
    return result

print(word_compression("geeksforgeeks", 2))
print(word_compression("qddxxxd", 3))
print(word_compression("ddxxxd", 3))
