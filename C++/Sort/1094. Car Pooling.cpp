class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> vec;
        for (auto& trip : trips) {
            vec.push_back({trip[1], 1, trip[0]});
            vec.push_back({trip[2], -1, trip[0]});
        }
        sort(vec.begin(), vec.end());
        int passengers = 0;
        for (auto& v : vec) {
            passengers += v[1] * v[2];
            if (passengers > capacity) return false;
        }
        return true;
    }
};