class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            *it += c;
            c = *it/10;
            *it = *it%10;
        }
        vector<int> res;
        if (c != 0) {
            res.push_back(c);
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        }
        else {
            return digits;
        }
    }
};