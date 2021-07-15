class Solution {
public:
    vector<int> debts;
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for (auto t : transactions) {
            int lender = t[0], borrower = t[1], amount = t[2];
            mp[lender] -= amount;
            mp[borrower] += amount;
        }   
        for (auto p : mp) {
            if (p.second != 0) debts.push_back(p.second);
        }
        return backtrack(0);
    }
    
    int backtrack(int start) {
        int res = INT_MAX;
        while (start < debts.size() && debts[start] == 0) start++;
        for (int i = start + 1; i < debts.size(); i++) {
            if (debts[i] * debts[start] < 0) {
                debts[i] += debts[start];
                res = min(res, 1 + backtrack(start + 1));
                debts[i] -= debts[start];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};