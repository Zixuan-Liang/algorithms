class Solution {
public:
    
    long long helper(int len, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        int maxLen = INT_MIN;
        for (int i = 0; i < cuts.size() + 1; i++) {
            if (i == 0) {
                maxLen = max(maxLen, cuts[0]);
            }
            else if (i == cuts.size()) {
                maxLen = max(maxLen, len - cuts.back());
            }
            else {
                maxLen = max(maxLen, cuts[i] - cuts[i-1]);
            }
        }
        return maxLen % 1000000007;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long maxH = helper(h, horizontalCuts);
        long long maxW = helper(w, verticalCuts);
        return (maxH * maxW) % 1000000007;
    }
};