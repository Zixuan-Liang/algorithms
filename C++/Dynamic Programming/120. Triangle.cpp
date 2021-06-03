class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int res = INT_MAX;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) triangle[i][j] += triangle[i-1][0];
                else if(j == i) triangle[i][j] += triangle[i-1][i-1];
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                if (i == triangle.size()-1) res = min(res, triangle[i][j]);
            }
        }
        return res;
    }
};