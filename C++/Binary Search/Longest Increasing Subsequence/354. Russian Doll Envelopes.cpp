// 前置题300，最长升序子数组

// times O(nlogn), space O(n)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 先按照宽从小到大排序，得到一个高的数组
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2)->bool{
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        vector<int> heights;
        for (auto& e : envelopes) heights.push_back(e[1]);
        vector<int> dp;
        for (int h : heights) { // 在高数组里查找最长严格升序子数组
            auto lower = lower_bound(dp.begin(), dp.end(), h);
            if (lower == dp.end()) {
                dp.push_back(h);
            }
            else {
                *lower = h;
            }
        }
        return dp.size();
    }
};