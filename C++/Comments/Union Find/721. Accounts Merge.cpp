class Solution {
public:
    
    unordered_map<string, string> parents;
    unordered_map<string, string> owners;
    unordered_map<string, int> ranks;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                owners[account[i]] = account[0];
                if (!parents.count(account[i])) {
                    parents[account[i]] = account[i];
                    ranks[account[i]] = 0;
                }
            }
            for (int i = 1; i < account.size() - 1; i++) { // 同一个account，相邻两个email进行union操作
                uni(account[i], account[i+1]);
            }
        }
        for (auto [key, value] : parents) { // 最后记得每个email都find一下，确保parent都指向root
            find(key);
        }
        unordered_map<string, pair<string, vector<string>>> merge; // merge哈希表：键：集合根，值：<拥有者名字，邮箱地址数组>
        for (auto [key, value] : parents) {
            if (!merge.count(value)) {
                merge[value].first = owners[key];
            }
            merge[value].second.push_back(key);
        }
        vector<vector<string>> ans;
        for (auto [key, value] : merge) {
            sort(value.second.begin(), value.second.end()); // 邮箱地址数组排序
            value.second.insert(value.second.begin(), value.first); // 把拥有者名字放在前面
            ans.emplace_back(value.second);
        }
        return ans;
    }
    
    string find(string x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void uni(string x, string y) {
        string xset = find(x), yset = find(y);
        if (xset != yset) {
            if (ranks[xset] < ranks[yset]) {
                parents[xset] = yset;
            }
            else {
                parents[yset] = xset;
            }
            if (ranks[xset] == ranks[yset]) {
                ranks[xset]++;
            }
        }
    }
};





