import numpy as np
import random

from itertools import chain
from functools import reduce
from operator import mul

class Array():
    def __init__(self, data):
        self.data = data
        self.shape = self.get_shape()
        self.flat = self.flatten()
    def get_shape(self):
        nest = self.data
        shape = []
        while type(nest) == list:
            shape.append(len(nest))
            nest = nest[0]
        return(tuple(shape))
    def flatten(self):
        iters = len(self.shape)
        new_data = self.data
        for _ in range(iters-1):
            new_data = list(chain.from_iterable(new_data))
        return new_data
    def reshape(self, shape, flat=None):
        if not flat:
            flat = self.flat
        if len(shape) == 1:
            assert shape[0] == -1 or shape[0] == len(flat)
            return flat
        else:
            if shape[-1] == -1:
                shape = list(shape)
                shape[-1] = len(flat) // reduce(mul, shape[:-1])
                shape = tuple(shape)
                assert len(flat) % reduce(mul, shape[:-1]) == 0
            assert len(flat) == reduce(mul, shape)
            n = reduce(mul, shape[1:])
            return [self.reshape(shape[1:], flat[i*n:(i+1)*n]) for i in range(len(flat)//n)]


while True:
    shape = []
    length = random.randint(5,10)
    for _ in range(length):
        shape.append(2)
    shape = tuple(shape)
    array = np.random.random_sample(shape)
    my_array = Array(array.tolist())
    assert array.shape == my_array.shape
    assert np.array_equal(array.flatten(), np.array(my_array.flatten()))
    assert np.array_equal(np.reshape(array, (2,2,-1)), np.array(my_array.reshape((2,2,-1))))
    print("passed")
