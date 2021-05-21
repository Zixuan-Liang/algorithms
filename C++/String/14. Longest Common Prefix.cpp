#include <vector>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        bool check = true;
        while (check && index < strs[0].size()) {
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                check = index < strs[i].size() && strs[i][index] == c;
                if (!check) break;
            }
            if (check) index++;
        }
        return strs[0].substr(0, index);
    }
};