class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0;
        int prev = 0;
        for (int rung : rungs) {
            int diff = rung - prev;
            if (diff > dist) {
                ans += (diff - 1) / dist;
            }
            prev = rung;
        }
        return ans;
    }
};