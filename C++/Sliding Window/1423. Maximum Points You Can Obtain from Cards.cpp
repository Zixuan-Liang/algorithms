class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int head = 0, tail = 0, n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            head += cardPoints[i];
        }
        int res = head + tail;
        for (int i = 0; i < k; i++) {
            head -= cardPoints[k - 1 - i];
            tail += cardPoints[n - 1 - i];
            res = max(res, head + tail);
        }
        return res;
    }
};