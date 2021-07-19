class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        vector<vector<int>> times;
        for (auto interval : intervals) {
            times.push_back({interval[0], 1});
            times.push_back({interval[1], -1});
        }
        sort(times.begin(), times.end());
        int rooms = 0;
        for (auto time : times) {
            rooms += time[1];
            ans = max(ans, rooms);
        }
        return ans;
    }
};