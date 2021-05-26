class Solution {
public:
    
    void backtrack(int n, vector<int>& res, unordered_set<int>& used, int curr) {
        if (res.size() == pow(2, n)) return ;
        res.push_back(curr);
        for (int i = 0; i < n; i++) {
            int candidate = curr ^ (1 << i);
            if (used.find(candidate) == used.end()) {
                used.insert(candidate);
                backtrack(n, res, used, candidate);
                // 这里不需要unchoose，因为任意路径都是可行的
            }
        }
    }
    
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> used = {0};
        backtrack(n, res, used, 0);
        return res;
    }
};
