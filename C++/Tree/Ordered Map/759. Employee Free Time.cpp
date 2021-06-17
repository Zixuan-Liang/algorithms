/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    
    // Solution from 56
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> currVec = {-1, -1};
        for (auto& v : intervals) {
            if (v[0] > currVec[1]) {
                if (currVec[0] != -1) res.push_back(currVec);
                currVec = v;
            }
            else {
                currVec[1] = max(currVec[1], v[1]);
            }
        }
        if (currVec[0] != -1) res.push_back(currVec);
        return res;
    }
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<vector<int>> intervals;
        for (auto s : schedule) {
            for (auto i : s) {
                intervals.push_back({i.start, i.end});
            }
        }
        intervals = merge(intervals);
        vector<Interval> res;
        for (int i = 1; i < intervals.size(); i++) {
            Interval interval(intervals[i-1][1], intervals[i][0]);
            res.push_back(interval);
        }
        return res;
    }
};








