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
        return arr[-1::-1]
    elif axis == 1:
        return [row[-1::-1] for row in arr]

def roll(arr, axis):
    

array = np.random.random_sample((2,2))
print(array.flatten().tolist() == flatten(array))
array = np.random.random_sample((2,2))
print(np.transpose(array).tolist() == transpose(array))
array = np.random.random_sample((2,2))
print(np.flip(array, 0).tolist() == flip(array.tolist(), 0))
array = np.random.random_sample((2,2))
print(np.flip(array, 1).tolist() == flip(array.tolist(), 1))
