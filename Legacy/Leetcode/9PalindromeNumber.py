# Determine whether an integer is a palindrome. Do this without extra space.
def is_palindrome(x):
    x = str(x)
    if x == x[::-1]:
        return True
    else:
        return False