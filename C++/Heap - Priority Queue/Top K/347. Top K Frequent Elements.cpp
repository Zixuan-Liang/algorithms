#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;
        // pair: {freq, value}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> topK;
        for (auto& [val, freq] : count) {
            topK.push({freq, val});
            if (topK.size() > k) {
                topK.pop();
            }
        }
        while (!topK.empty()) {
            ans.push_back(topK.top().second);
            topK.pop();
        }
        return ans;
    }
};