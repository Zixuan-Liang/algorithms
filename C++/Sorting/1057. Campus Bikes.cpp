class Solution {
public:
    // bucket sort
    // O(N*M) time, O(N*M) space
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // bucket sort since range of distance is [0, 2000]
        vector<vector<pair<int, int>>> buckets(2001); // buckets[i] is the vector<worker id, bike id> with distance i
        int n = workers.size(), m = bikes.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[dis].push_back({i, j});
            }
        }
        vector<int> res(n, -1);
        vector<bool> bikeUsed(m, false);
        for (int d = 0; d <= 2000; d++) {
            for (int k = 0; k < buckets[d].size(); k++) {
                if (res[buckets[d][k].first] == -1 && !bikeUsed[buckets[d][k].second]) {
                    bikeUsed[buckets[d][k].second] = true;
                    res[buckets[d][k].first] = buckets[d][k].second;
                }
            }
        }
        return res;
    }
};