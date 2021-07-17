# INT_MAX = 2147483647

class Solution:
    def isPalindrome(self, x: int) -> bool:
        CAP = 214748364
        if x < 0: return False
        backup = x
        reverse = 0
        while x:
            if reverse > CAP or (reverse == CAP and x%10 >= 8): return False
            reverse = reverse * 10 + x%10
            x //= 10
        return reverse == backup