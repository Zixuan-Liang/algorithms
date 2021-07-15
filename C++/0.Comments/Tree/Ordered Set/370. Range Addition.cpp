class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, int> operations;
        for (auto update : updates) {
            operations[update[0]] += update[2];
            operations[update[1] + 1] -= update[2];
        }
        vector<int> ans(length, 0);
        if (operations.empty()) {
            return ans;
        }
        else {
            int curr = 0;
            for (auto it = begin(operations); it != end(operations); it++) {
                int start = it == begin(operations) ? 0 : prev(it)->first;
                int end = it->first - 1;
                int i = start;
                while (start <= end && i <= end) {
                    ans[i++] = curr;
                }
                curr += it->second;
            }
        }
        return ans;
    }
};