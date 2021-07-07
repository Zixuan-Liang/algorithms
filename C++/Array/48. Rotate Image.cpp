class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp1, temp2, temp3, temp4;
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < (n+1)/2; j++) {
                temp1 = matrix[n-1-j][i]; temp2 = matrix[i][j]; temp3 = matrix[j][n-1-i]; temp4 = matrix[n-1-i][n-1-j];
                matrix[i][j] = temp1; matrix[j][n-1-i] = temp2; matrix[n-1-i][n-1-j] = temp3; matrix[n-1-j][i] = temp4;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp1, temp2, temp3, temp4;
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < (n+1)/2; j++) {
                swap(matrix[i][j], matrix[j][n-1-i]);
                swap(matrix[i][j], matrix[n-1-i][n-1-j]);
                swap(matrix[i][j], matrix[n-1-j][i]);
            }
        }
    }
};