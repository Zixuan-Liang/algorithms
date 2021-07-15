class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int len = m * n;
        int r = 0, c = 0;
        string next = "right";
        while (true) {
            res.push_back(matrix[r][c]); 
            if (res.size() == len) break;
            matrix[r][c] = 101; // 101是一个超出取值范围的数，表示已访问
            if (next == "right") {
                if (c+1<n && matrix[r][c+1]!=101) c++;
                else { next = "down"; r++; }
            }
            else if (next == "down") {
                if (r+1<m && matrix[r+1][c]!=101) r++;
                else { next = "left"; c--; }
            }
            else if (next == "left") {
                if (c-1>=0 && matrix[r][c-1]!=101) c--;
                else { next = "up"; r--; }
            }
            else {
                if (r-1>=0 && matrix[r-1][c]!=101) r--;
                else { next = "right"; c++; }
            }
        }
        return res;
    }
};