from collections import OrderedDict

# 用OrderedDict实现哈希+双链表
# 哈希实现O(1)的读取和存储
# 双链表实现O(1)修改顺序

class LRUCache(OrderedDict):

    def __init__(self, capacity: int):
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self:
            return -1
        self.move_to_end(key)
        return self[key]

    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key)
        self[key] = value
        if len(self) > self.capacity:
            self.popitem(last = False)

# 手动实现OrderedDict
class LRUCacheOldSchool:

    def __init__(self, capacity):
        self.capacity = capacity
        self.linkedList = {'head':{'val':0, 'prev':None, 'next':'tail'}, 
                            'tail':{'val':0, 'prev':'head', 'next':None}}

    def moveKeyToTail(self, key):
        prev = self.linkedList[key]['prev']
        next = self.linkedList[key]['next']
        self.linkedList[prev]['next'] = next
        self.linkedList[next]['prev'] = prev
        end = self.linkedList['tail']['prev']
        self.linkedList[end]['next'] = key
        self.linkedList[key]['prev'] = end
        self.linkedList[key]['next'] = 'tail'
        self.linkedList['tail']['prev'] = key

    def removeHead(self):
        key = self.linkedList['head']['next']
        next = self.linkedList[key]['next']
        self.linkedList['head']['next'] = next
        self.linkedList[next]['prev'] = 'head'
        self.linkedList.pop(key)

    def get(self, key):
        if key not in self.linkedList:
            return -1
        self.moveKeyToTail(key)
        return self.linkedList[key]['val']

    def put(self, key, value):
        if key in self.linkedList:
            self.moveKeyToTail(key)
            self.linkedList[key]['val'] = value
        else:
            end = self.linkedList['tail']['prev']
            self.linkedList[key] = {'val':value, 'prev':end, 'next':'tail'}
            self.linkedList[end]['next'] = key
            self.linkedList['tail']['prev'] = key
        if len(self.linkedList) > self.capacity+2:
            self.removeHead()



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)