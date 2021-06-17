class Solution {
public:
    
    void backtrack(int k, int n, vector<vector<int>>& res, vector<int>& comb, int sum, int num) {
        if (comb.size() == k && sum == n) {
            res.push_back(comb);
        }
        else {
            for (int i = num + 1; i <= 9; i++) {
                comb.push_back(i);
                sum += i;
                backtrack(k, n, res, comb, sum, i);
                sum -= i;
                comb.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(k, n, res, comb, 0, 0);
        return res;
    }
};