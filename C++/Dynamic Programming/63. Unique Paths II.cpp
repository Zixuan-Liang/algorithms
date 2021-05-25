class Solution {
public:
    
    int helper(int x, int y, map<pair<int, int>, int>& memo, vector<vector<int>>& obstacleGrid) {
        if (memo.find({x, y}) == memo.end()) {
            int res;
            if(obstacleGrid[x][y] == 1) {
                res = 0;
            }
            else if (x == 0) {
                res = helper(x, y-1, memo, obstacleGrid);
            }
            else if (y == 0) {
                res = helper(x-1, y, memo, obstacleGrid);
            }
            else {
                res = helper(x-1, y, memo, obstacleGrid) + helper(x, y-1, memo, obstacleGrid);
            }
            memo[{x, y}] = res;
        }
        return memo[{x, y}];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        map<pair<int, int>, int> memo;
        memo[{0, 0}] = 1;
        return helper(m-1, n-1, memo, obstacleGrid);
    }
};
