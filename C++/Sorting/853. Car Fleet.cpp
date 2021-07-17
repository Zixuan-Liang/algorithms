class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> cars;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        int ans = 0;
        double frontFleetT2D = 0;
        for (int i = n - 1; i >= 0; i--) {
            double thisCarT2D = 1.0 * (target - cars[i][0]) / cars[i][1];
            if (thisCarT2D > frontFleetT2D) {
                ans++;
                frontFleetT2D = thisCarT2D;
            }
        }
        return ans;
    }
};