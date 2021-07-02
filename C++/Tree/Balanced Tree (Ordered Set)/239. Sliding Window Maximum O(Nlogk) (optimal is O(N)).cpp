class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*window.rbegin());
        for (int i = k; i < nums.size(); i++) {
            window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
            ans.push_back(*window.rbegin());
        }
        return ans;
    }
};