# basic operations
def shape(arr):
    return (len(arr), len(arr[0])) 

# changing array shape
def flatten(arr):
    flat = [item for row in arr for item in row]
    return flat

# transpose-like operations
def transpose(arr):
    tran = list(map(list, zip(*arr)))
    return tran

def swapaxes(arr, axis1=0, axis2=1):
    return transpose(arr)

# joining arrays
def concatenate(a, b, axis):
    if axis == 0:
        return a + b
    elif axis == 1:
        arr = []
        for a_row, b_row in zip(a,b):
            arr.append(a_row + b_row)
        return arr

# adding and removing elements
def delete(arr, obj, axis=None):
    if type(obj) == int:
        obj = set([obj])
    else:
        obj = set(obj)
    if axis is None or axis == 0:
        if axis is None:
            arr = flatten(arr)
        new_arr = []
        for i in range(len(arr)):
            if i not in obj:
                new_arr.append(arr[i])
        return new_arr
    elif axis == 1:
        new_arr = []
        for i in range(len(arr)):
            new_row = []
            for j in range(len(arr[i])):
                if j not in obj:
                    new_row.append(arr[i][j])
            new_arr.append(new_row)
        return new_arr    

# rearranging elements
def flip(arr, axis):
    if axis == 0:
        return arr[::-1]
    if axis == 1:
        return [row[::-1] for row in arr]

def fliplr(arr):
    return flip(arr, 1)

def flipud(arr):
    return flip(arr, 0)

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

# basic linear algebra tools in pure python
def zeros_matrix(rows, cols):
    M = []
    while len(M) < rows:
        M.append([])
        while len(M[-1]) < cols:
            M[-1].append(0.0)
    return M

def identity_matrix(n):
    IdM = zeros_matrix(n, n)
    for i in range(n):
        IdM[i][i] = 1.0
    return IdM

def copy_matrix(M):
    rows = len(M)
    cols = len(M[0])
    MC = zeros_matrix(rows, cols)
    for i in range(rows):
        for j in range(cols):
            MC[i][j] = M[i][j]
    return MC

def print_matrix(M, decimals=3):
    for row in M:
        print([round(x,decimals)+0 for x in row])

def transpose2(M):
    if not isinstance(M[0],list):
        M = [M]
    rows = len(M)
    cols = len(M[0])
    MT = zeros_matrix(cols, rows)
    for i in range(rows):
        for j in range(cols):
            MT[j][i] = M[i][j]
    return MT

def matrix_addition(A, B):
    rowsA = len(A)
    colsA = len(A[0])
    rowsB = len(B)
    colsB = len(B[0])
    if rowsA != rowsB or colsA != colsB:
        raise ArithmeticError('Matrices are NOT the same size.')
    C = zeros_matrix(rowsA, colsB)
    for i in range(rowsA):
        for j in range(colsB):
            C[i][j] = A[i][j] + B[i][j]
    return C

def matrix_subtraction(A, B):
    rowsA = len(A)
    colsA = len(A[0])
    rowsB = len(B)
    colsB = len(B[0])
    if rowsA != rowsB or colsA != colsB:
        raise ArithmeticError('Matrices are NOT the same size.')
    C = zeros_matrix(rowsA, colsB)
    for i in range(rowsA):
        for j in range(colsB):
            C[i][j] = A[i][j] - B[i][j]
    return C

def matrix_multiply(A, B):
    rowsA = len(A)
    colsA = len(A[0])
    rowsB = len(B)
    colsB = len(B[0])
    if colsA != rowsB:
        raise ArithmeticError('Number of A columns must equal number of B rows.')
    C = zeros_matrix(rowsA, colsB)
    for i in range(rowsA):
        for j in range(colsB):
            total = 0
            for ii in range(colsA):
                total += A[i][ii] * B[ii][j]
            C[i][j] = total
    return C

def multiply_matrices(li):
    matrix_product = li[0]
    for matrix in li[1:]:
        matrix_product = matrix_multiply(matrix_product, matrix)
    return matrix_product

def check_matrix_equality(A, B, tol=None):
    if len(A) != len(B) or len(A[0]) != len(B[0]):
        return False
    for i in range(len(A)):
        for j in range(len(A[0])):
            if tol == None:
                if A[i][j] != B[i][j]:
                    return False
            else:
                if round(A[i][j],tol) != round(B[i][j],tol):
                    return False
    return True

def unitize_vector(vector):
    if len(vector) > 1 and len(vector[0]) > 1:
        raise ArithmeticError('Vector must be a row or column vector.')
    rows = len(vector)
    cols = len(vector[0])
    mag = 0
    for row in vector:
        for value in row:
            mag += value ** 2
    mag = mag ** 0.5
    new = copy_matrix(vector)
    for i in range(rows):
        for j in range(cols):
            new[i][j] = new[i][j] / mag
    return new