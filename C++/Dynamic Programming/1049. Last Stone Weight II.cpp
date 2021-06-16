#include <numeric>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> dp = {0};        
        int sum = accumulate(stones.begin(), stones.end(), 0);
        for (int num : stones) {
            unordered_set<int> update;
            for (int partialSum : dp) {
                update.insert(partialSum + num);
            }
            dp.merge(update);
        }
        int res = INT_MAX;
        for (int partialSum : dp) {
            res = min(res, abs(sum - partialSum - partialSum));
        }
        return res;
    }
};

