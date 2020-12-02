# arr2 is shuffle of arr1, missing one element.

def missing_value(arr1, arr2):
    return (sum(arr1) - sum(arr2))

def missing_value_2(arr1, arr2):
    arr1.sort()
    arr2.sort()
    for pair in list(zip(arr1, arr2)):
        if pair[0] != pair[1]:
            return pair[0]
    return arr1[0]

