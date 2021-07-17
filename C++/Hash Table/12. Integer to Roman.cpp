#include <string>

class Solution {
public:
    string intToRoman(int num) {
        string D1[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string R1 = D1[num%10];
        string D2[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string R2 = D2[num/10%10];
        string D3[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string R3 = D3[num/100%10];
        string D4[4] = {"", "M", "MM", "MMM"};
        string R4 = D4[num/1000%10];
        return R4 + R3 + R2 + R1;
    }
};