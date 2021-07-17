#include <algorithm>

class Solution {
public:
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
};