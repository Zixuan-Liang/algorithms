class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) {
            return mat;
        }
        else {
            int n = r * c, old_c = mat[0].size();
            vector<vector<int>> ans(r, vector<int>(c));
            for (int i = 0; i < n; i++) {
                ans[i/c][i%c] = mat[i/old_c][i%old_c];
            }
            return ans;
        }
    }
};