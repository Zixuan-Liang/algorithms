#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
        int index = 0;
        
        unordered_map<string, int> R4;
        R4[""] = 0; R4["M"] = 1000; R4["MM"] = 2000; R4["MMM"] = 3000;
        string S4 = "";
        while (index < s.size() && s[index] == 'M') {
            S4 += string(1, s[index]);
            index++;
        }
        int D4 = R4[S4];
        
        unordered_map<string, int> R3;
        R3[""] = 0; R3["C"] = 100; R3["CC"] = 200; R3["CCC"] = 300; R3["CD"] = 400;
        R3["D"] = 500; R3["DC"] = 600; R3["DCC"] = 700; R3["DCCC"] = 800; R3["CM"] = 900;
        string S3 = "";
        while (index < s.size() && (s[index] == 'C' || s[index] == 'D' || s[index] == 'M')) {
            S3 += string(1, s[index]);
            index++;
        }
        int D3 = R3[S3];        
        
        unordered_map<string, int> R2;
        R2[""] = 0; R2["X"] = 10; R2["XX"] = 20; R2["XXX"] = 30; R2["XL"] = 40;
        R2["L"] = 50; R2["LX"] = 60; R2["LXX"] = 70; R2["LXXX"] = 80; R2["XC"] = 90;
        string S2 = "";
        while (index < s.size() && (s[index] == 'X' || s[index] == 'L' || s[index] == 'C')) {
            S2 += string(1, s[index]);
            index++;
        }
        int D2 = R2[S2];
        
        unordered_map<string, int> R1;
        R1[""] = 0; R1["I"] = 1; R1["II"] = 2; R1["III"] = 3; R1["IV"] = 4;
        R1["V"] = 5; R1["VI"] = 6; R1["VII"] = 7; R1["VIII"] = 8; R1["IX"] = 9;
        string S1 = "";
        while (index < s.size() && (s[index] == 'I' || s[index] == 'V' || s[index] == 'X')) {
            S1 += string(1, s[index]);
            index++;
        }
        int D1 = R1[S1];
        
        return D4 + D3 + D2 + D1;
        
    }
};