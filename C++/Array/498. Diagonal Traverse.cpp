class Solution {
    
    const int UPRIGHT = 0;
    const int DOWNLEFT = 1;
    const vector<vector<int>> moves = {{-1,1}, {1,-1}};
    
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = 0;
        int dir = UPRIGHT;
        while (!(r == m-1 && c == n-1)) {
            res.push_back(mat[r][c]);
            int nr = r + moves[dir][0];
            int nc = c + moves[dir][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                r = nr; c = nc;
            }
            else {
                if (dir == UPRIGHT && c+1 < n || dir == DOWNLEFT && r+1 >= m)
                    c++;
                else 
                    r++;
                dir = 1 - dir;
            }
        }
        res.push_back(mat[r][c]);
        return res;
    }
};