// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         vector<vector<int>> vec;
//         for (auto& trip : trips) {
//             vec.push_back({trip[1], 1, trip[0]});
//             vec.push_back({trip[2], -1, trip[0]});
//         }
//         sort(vec.begin(), vec.end());
//         int passengers = 0;
//         for (auto& v : vec) {
//             passengers += v[1] * v[2];
//             if (passengers > capacity) return false;
//         }
//         return true;
//     }
// };

#include <numeric>

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> buckets(1001);
        for (auto& trip : trips) {
            buckets[trip[1]].push_back(trip[0]);
            buckets[trip[2]].push_back(-trip[0]);
        }
        int passengers = 0;
        for (auto& bucket : buckets) {
            passengers += accumulate(bucket.begin(), bucket.end(), 0);
            if (passengers > capacity) return false;
        }
        return true;
    }
};