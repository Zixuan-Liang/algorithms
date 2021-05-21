class Solution {
    
    vector<vector<string>> lookup = {{},{},{"a","b","c"},{"d","e","f"},{"g","h","i"},
    {"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> firstD = lookup[digits[0] - '0'];
        if (digits.size() == 1) return firstD;
        vector<string> res;
        // substr(startPos, len)
        vector<string> restD = letterCombinations(digits.substr(1));
        for (string& c1: firstD) {
            for (string& c2: restD) {
                res.emplace_back(c1+c2);
            }
        }
        return res;
    }
};