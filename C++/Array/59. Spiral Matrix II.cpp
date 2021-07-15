class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int r = 0, c = 0;
        string next = "right";
        int num = 0;
        while (true) {
            res[r][c] = ++num;
            if (num == n*n) break;
            if (next == "right") {
                if (c+1<n && res[r][c+1]==0) c++;
                else { next = "down"; r++; }
            }
            else if (next == "down") {
                if (r+1<n && res[r+1][c]==0) r++;
                else { next = "left"; c--; }
            }
            else if (next == "left") {
                if (c-1>=0 && res[r][c-1]==0) c--;
                else { next = "up"; r--; }
            }
            else {
                if (r-1>=0 && res[r-1][c]==0) r--;
                else { next = "right"; c++; }
            }
        }
        return res;
    }
};

