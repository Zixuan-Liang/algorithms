class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> orders(26, 26);
        for (int i = 0; i < order.size(); i++) orders[order[i] - 'a'] = i;
        sort(begin(str), end(str), [&](const char c1, const char c2)->bool {
            return orders[c1 - 'a'] < orders[c2 - 'a'];
        });
        return str;
    }
};