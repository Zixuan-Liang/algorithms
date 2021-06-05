class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = ratings[i] > ratings[i-1] ? left[i-1] + 1 : left[i];
            right[n-1-i] = ratings[n-1-i] > ratings[n-i] ? right[n-i] + 1 : right[n-1-i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(left[i], right[i]);
        }
        return res;
    }
};