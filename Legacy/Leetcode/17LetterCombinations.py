# Given a digit string, return all possible letter combinations that the number could represent.
# A mapping of digit to letters (just like on the telephone buttons) is given below.
import itertools

def letter_com(digits):
    length = len(digits)
    if length ==  0:
        return []
    bucket = ['' for i in range(length)]
    dict = {'1':'', '2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
    for i in range(length):
        bucket[i] = dict[digits[i]]
    result = list(itertools.product(*bucket))
    result = [''.join(ele) for ele in result]
    return result

print letter_com("23")