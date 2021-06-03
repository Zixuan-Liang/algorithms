#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> memo;
        for (int n : nums) memo.insert(n);
        for (int n : nums) {
            if (memo.find(n-1) == memo.end()) {
                int streak = 0;
                int currNum = n;
                while (memo.find(currNum) != memo.end()) {
                    streak++;
                    currNum++;
                }
                res = max(res, streak);
            }
        }
        return res;
    }
};