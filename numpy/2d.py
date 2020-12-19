import numpy as np

def flatten(arr):
    flat = [item for row in arr for item in row]
    return flat

def transpose(arr):
    tran = list(map(list, zip(*arr)))
    return tran

def concatenate(a, b, axis):
    if axis == 0:
        return a + b
    elif axis == 1:
        arr = []
        for a_row, b_row in zip(a,b):
            arr.append(a_row + b_row)
        return arr

def flip(arr, axis):
    if axis == 0:
        return arr[::-1]
    if axis == 1:
        return [row[::-1] for row in arr]

def roll(arr, shift, axis=None):
    if axis is None:
        rows, cols = len(arr), len(arr[0])
        flat = flatten(arr)
        shift = shift % len(flat)
        flat = flat[-shift:] + flat[:-shift]
        new_arr = []
        for i in range(rows):
            row = []
            for j in range(cols):
                row.append(flat[i * cols + j])
            new_arr.append(row)
        return new_arr
    if axis == 0:
        shift = shift % len(arr)
        return arr[-shift:] + arr[:-shift]
    if axis == 1:
        shift = shift % len(arr[0])
        return [row[-shift:] + row[:-shift] for row in arr]
            
def rot90_clock(arr):
    rot = list(map(list, zip(*reversed(arr))))
    return rot

def rot90_counter_clock(arr):
    tran = transpose(arr)
    return tran[::-1]
