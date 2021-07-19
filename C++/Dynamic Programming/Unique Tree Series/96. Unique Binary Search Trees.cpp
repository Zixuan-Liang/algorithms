class Solution {
public:
    
    int helper(int start, int end, unordered_map<int, int>& memo) {
        if (memo.find(end - start + 1) == memo.end()) {
            int res;
            if (start > end) {
                res = 1;
            }
            else {
                res = 0;
                for (int i = start; i <= end; i++) {
                    res += helper(start, i-1, memo) * helper(i+1, end, memo);
                }
            }
            memo[end - start + 1] = res;
        }
        return memo[end - start + 1];
    }
    
    int numTrees(int n) {
        unordered_map<int, int> memo;
        return helper(1, n, memo);
    }
};