// Same as 198 house robber question

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> buckets(10001, 0);
        for (int n : nums) buckets[n] += n;
        int maxTwo = 0;
        int maxOne = 0;
        for (int i = 0; i < buckets.size(); i++) {
            int maxCurr = max(maxTwo + buckets[i], maxOne);
            maxTwo = maxOne;
            maxOne = maxCurr;
        }
        return maxOne;
    }
};