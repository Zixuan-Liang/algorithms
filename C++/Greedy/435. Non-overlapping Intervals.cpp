class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1], prev = 0, count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[prev][1] > intervals[i][0]) {
                if (intervals[prev][1] > intervals[i][1]) {
                    prev = i;
                }
                count++;
            }
            else {
                prev = i;
            }
        }
        return count;
    }
};

