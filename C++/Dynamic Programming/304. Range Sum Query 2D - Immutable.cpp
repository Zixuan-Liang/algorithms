class NumMatrix {
    
    int m;
    int n;
    vector<vector<int>> prefix;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        prefix = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int a = prefix[row2][col2] + prefix[row1-1][col1-1];
        int b = prefix[row2][col1-1] + prefix[row1-1][col2];
        return a-b;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */