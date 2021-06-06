class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0, n = cardPoints.size();
        if (n <= k) {
            for (int point : cardPoints) {
                res += point;
            }
            return res;
        }
        vector<int> begin = {0}, end = {0};
        for (int i = 0; i < k; i++) {
            begin.push_back(begin.back()+cardPoints[i]);
            end.push_back(end.back()+cardPoints[n-1-i]);
        }
        for (int i = 0; i < k+1; i++) {
            res = max(res, begin[i] + end[k-i]);
        }
        return res;
    }
};