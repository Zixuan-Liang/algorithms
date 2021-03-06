class Solution {
    
    int sum;
    vector<int> prefixSum;
    
public:
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) {
            prefixSum.push_back(prefixSum.back() + w[i]);
        }
        sum = prefixSum.back();
    }
    
    int pickIndex() {
        int randNum = rand()%sum + 1;
        auto lb = lower_bound(prefixSum.begin(), prefixSum.end(), randNum);
        return lb - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */