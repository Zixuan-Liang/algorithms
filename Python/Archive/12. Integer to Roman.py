class Solution:
    def intToRoman(self, num: int) -> str:
        D1 = {0: '', 1: 'I', 2: 'II', 3: 'III', 4: 'IV', 5: 'V', 6: 'VI', 7: 'VII', 8: 'VIII', 9: 'IX'}
        R1 = D1[num%10]
        D2 = {0: '', 1: 'X', 2: 'XX', 3: 'XXX', 4: 'XL', 5: 'L', 6: 'LX', 7: 'LXX', 8: 'LXXX', 9: 'XC'}
        R2 = D2[num//10%10]
        D3 = {0: '', 1: 'C', 2: 'CC', 3: 'CCC', 4: 'CD', 5: 'D', 6: 'DC', 7: 'DCC', 8: 'DCCC', 9: 'CM'}
        R3 = D3[num//100%10]
        D4 = {0: '', 1: 'M', 2: 'MM', 3: 'MMM'}
        R4 = D4[num//1000%10]
        return R4 + R3 + R2 + R1