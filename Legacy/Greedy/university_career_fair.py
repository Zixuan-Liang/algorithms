def max_events(n, arrival, duration):
    end = [arrival[i] + duration[i] for i in range(n)]
    arr_end = list(zip(arrival, end))
    arr_end.sort(key=lambda x: x[1])
    events = 0
    end = 0
    for item in arr_end:
        if item[0] >= end:
            events += 1
            end = item[1]
    return events

print(max_events(5, [1, 3, 3, 5, 7], [2, 2, 1, 2, 1]))
print(max_events(7, [1, 3, 5, 7, 9, 10, 11], [3, 3, 3, 3, 3, 1, 1]))
