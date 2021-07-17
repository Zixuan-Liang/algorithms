class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sequence;
        for (int n : nums) {
            auto lb = lower_bound(begin(sequence), end(sequence), n);
            if (lb == end(sequence)) {
                sequence.push_back(n);
            }
            else {
                *lb = n;
            }
        }
        return sequence.size();
    }
};