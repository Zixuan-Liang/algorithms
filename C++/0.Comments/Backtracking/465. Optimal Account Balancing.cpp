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
        while (start < debts.size() && debts[start] == 0) start++; // 跳过收支平衡的（0）
        for (int i = start + 1; i < debts.size(); i++) {
            if (debts[i] * debts[start] < 0) { // 往后找出与当前不一样的进行回溯，当前为正的找负，当前为负的找正，然后直接把当前的债务全部转移给后面的
                debts[i] += debts[start];
                res = min(res, 1 + backtrack(start + 1)); // 更新答案
                debts[i] -= debts[start];
            }
        }
        return res == INT_MAX ? 0 : res; // 如果答案没更新过，说明不需要进行任何操作
    }
};