#include <vector>
#include <string>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        // numRows个子字符串
        vector<string> strVec(numRows, "");
        // 一次循环的长度
        int r = numRows * 2 - 2;
        int idx;
        for (int i = 0; i < s.size(); i++) {
            // 对循环长度取余
            idx = i%r;
            // 取得实际对应子符串下标
            idx = (idx >= numRows) ? 2*(numRows-1)-idx : idx;
            // 添加到原来子字符串后面
            strVec[idx] += s[i];
        }
        string res = "";
        // 合并
        for (string& str : strVec) {
            res += str;
        }
        return res;
    }
};