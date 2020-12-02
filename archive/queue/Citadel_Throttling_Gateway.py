import collections
def droppedRequests(requestTime):
    # Write your code here

    Q1 = []
    Q20 = []
    Q60 = []
    count = 0
    for v in requestTime:
        while len(Q1) > 0 and  v - Q1[0] >= 1:
            Q1.pop(0)
        while len(Q20) > 0 and  v - Q20[0] >= 10:
            Q20.pop(0)
        while len(Q60) > 0 and  v - Q60[0] >= 60:
            Q60.pop(0)
        drop = 0
        if len(Q1) < 3:
            Q1.append(v)
        else:
            drop = 1
            Q1.pop(0)
            Q1.append(v)

        if len(Q20) < 20:
            Q20.append(v)
        else:
            drop = 1
            Q20.pop(0)
            Q20.append(v)
        
        if len(Q60) < 60:
            Q60.append(v)
        else:
            drop = 1
            Q60.pop(0)
            Q60.append(v)
        count += drop
        # print(Q1, Q20, Q60)


    return count

print(droppedRequests([1,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,11,11,11,11]))