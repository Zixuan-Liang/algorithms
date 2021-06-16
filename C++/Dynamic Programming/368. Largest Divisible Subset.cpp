class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        unordered_map<int, unordered_set<int>> subsets; // key: the largest element in a valid subset
        subsets[-1] = unordered_set<int>();
        sort(nums.begin(), nums.end());
        for (int n : nums) {
            int key = -1, len = 0;
            for (auto& item : subsets) {
                if (n % item.first == 0 && item.second.size() > len) {
                    key = item.first;
                    len = item.second.size();
                }
            }
            subsets[n] = subsets[key];
            subsets[n].insert(n);
        }
        int key = -1, len = 0;
        for (auto& item : subsets) {
            if (item.second.size() > len) {
                key = item.first;
                len = item.second.size();
            }
        }
        vector<int> res;
        for (int n : subsets[key]) {
            res.push_back(n);
        }
        return res;
    }
};