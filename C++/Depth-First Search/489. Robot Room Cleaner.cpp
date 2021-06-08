/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void backtrack(Robot& robot, vector<int> p, int d, vector<vector<int>>& directions, set<vector<int>>& visited) {
        visited.insert(p);
        robot.clean();
        for (int i = 0 ; i < 4; i++) {
            int nd = (d + i) % 4;
            vector<int> np = {p[0] + directions[nd][0], p[1] + directions[nd][1]};
            if (visited.find(np) == visited.end() && robot.move()) {
                backtrack(robot, np, nd, directions, visited);
                goBack(robot);
            }
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        set<vector<int>> visited;
        backtrack(robot, {0, 0}, 0, directions, visited);
    }
};

