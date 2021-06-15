class Solution {
    
    vector<vector<string>> candidates = {{"1","1"},{"8","8"},{"6","9"},{"9","6"}};

public:
    
    vector<string> helper(int n, int m) {
        if (n == 0) return {""};
        if (n == 1) return {"0","1","8"};
        vector<string> vec = helper(n-2, m);
        vector<string> res;
        for (int i = 0; i < vec.size(); i++) {
            string s = vec[i];
            if (n != m) res.push_back("0" + s + "0");
            for (auto cand : candidates) {
                res.push_back(cand[0] + s + cand[1]);
            }
        }
        return res;
    }
    
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
};