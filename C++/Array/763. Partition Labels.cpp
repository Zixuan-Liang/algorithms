class Solution {
public:
    
    vector<int> merge(vector<vector<int>>& intervals) {
        vector<int> ans;
        int start = -1, end = -1;
        for (auto interval : intervals) {
            if (interval[0] > end) {
                if (end != -1) ans.push_back(end - start + 1);
                start = interval[0];
                end = interval[1];
            }
            else {
                end = max(end, interval[1]);
            }
        }
        if (end != -1) ans.push_back(end - start + 1);
        return ans;
    }
    
    vector<int> partitionLabels(string s) {
        vector<vector<int>> positions(26);
        for (int i = 0; i < size(s); i++) {
            positions[s[i] - 'a'].push_back(i);
        }
        vector<vector<int>> intervals;
        for (auto p : positions) {
            if (size(p) > 0) intervals.push_back({p[0], p.back()}); // start, end
        }
        sort(begin(intervals), end(intervals));
        return merge(intervals);
    }
};