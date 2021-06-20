class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        for (int n : nums) minNum = min(minNum, n);
        int res = 0;
        for (int n : nums) res += n - minNum;
        return res;
    }
};