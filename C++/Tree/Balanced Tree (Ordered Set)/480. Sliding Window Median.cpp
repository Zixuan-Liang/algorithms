class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large;
        bool odd = k%2==1;
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                if (nums[i - k] <= *small.rbegin())
                    small.erase(small.find(nums[i-k]));
                else
                    large.erase(large.find(nums[i-k]));
            }
            
            small.insert(nums[i]);
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
            
            if (small.size() < large.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
            
            if (i >= k - 1) {
                if (odd)
                    res.push_back(*small.rbegin());
                else
                    res.push_back((1.0 * *small.rbegin() + 1.0 * *large.begin()) / 2);
            }
        }
        return res;
    }
};