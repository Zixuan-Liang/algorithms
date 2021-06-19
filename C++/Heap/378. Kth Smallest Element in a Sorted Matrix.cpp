class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>> pq;
        for (int r = 0; r < min(k, n); r++) {
            pq.push({-matrix[r][0], -r, -0});
        }
        
        int element, r, c;
        while (k) {
            vector<int> top = pq.top();
            element = -top[0], r = -top[1], c = -top[2];
            pq.pop();
            if (c < n - 1) {
                pq.push({-matrix[r][c+1], -r, -(c+1)});
            }
            k--;
        }
        return element;
    }
};