class Solution {
public:
    
    int helper(vector<vector<int>>& grid, map<pair<int, int>, int>& memo, int x, int y) {
        if (memo.find({x, y}) == memo.end()) {
            int res;
            if (x == 0 && y == 0) {
                res = grid[0][0];
            }
            else if (x == 0) {
                res = grid[x][y] + helper(grid, memo, x, y-1);
            }
            else if (y == 0) {
                res = grid[x][y] + helper(grid, memo, x-1, y);
            }
            else {
                res = grid[x][y] + min(helper(grid, memo, x, y-1), helper(grid, memo, x-1, y));
            }
            memo[{x, y}] = res;
        }
        return memo[{x, y}];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        map<pair<int, int>, int> memo;
        int m = grid.size(), n = grid[0].size();
        return helper(grid, memo, m-1, n-1);
    }
};