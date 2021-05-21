class Solution:
    def romanToInt(self, s: str) -> int:
        index = 0
        
        R4 = {'': 0, 'M': 1000, 'MM': 2000, 'MMM': 3000}
        S4 = ''
        while index < len(s) and s[index] == 'M':
            S4 += s[index]
            index += 1
        D4 = R4[S4]
        
        R3 = {'': 0, 'C': 100, 'CC': 200, 'CCC': 300, 'CD': 400, 'D': 500, 'DC': 600, 'DCC': 700, 'DCCC': 800, 'CM': 900}
        S3 = ''
        while index < len(s) and s[index] in ['C', 'D', 'M']:
            S3 += s[index]
            index += 1
        D3 = R3[S3]
        
        R2 = {'': 0, 'X': 10, 'XX': 20, 'XXX': 30, 'XL': 40, 'L': 50, 'LX': 60, 'LXX': 70, 'LXXX': 80, 'XC': 90}
        S2 = ''
        while index < len(s) and s[index] in ['X', 'L', 'C']:
            S2 += s[index]
            index += 1
        D2 = R2[S2]
        
        R1 = {'': 0, 'I': 1, 'II': 2, 'III': 3, 'IV': 4, 'V': 5, 'VI': 6, 'VII': 7, 'VIII': 8, 'IX': 9}
        S1 = s[index:]
        D1 = R1[S1]
        
        return D4 + D3 + D2 + D1