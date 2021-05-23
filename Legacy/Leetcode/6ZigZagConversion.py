# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
# (you may want to display this pattern in a fixed font for better legibility)
import math
def convert(s, numRows):
    if numRows == 1:
        return s
    result = ""
    length = len(s)
    num_in_block = 2 * (numRows - 1)
    for i in range(numRows):
        if i == 0 or i == numRows - 1:
            for j in range(i, length, num_in_block):
                result += s[j]
        else:
            next_idx = num_in_block - i
            for j in range(i, length, num_in_block):
                if next_idx < length:
                    result += s[j] + s[next_idx]
                else:
                    result += s[j]
                next_idx += num_in_block
    return result

print convert("PAYPALISHIRING", 3)