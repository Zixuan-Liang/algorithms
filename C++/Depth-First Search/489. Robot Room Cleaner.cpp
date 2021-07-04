struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        auto intHash = hash<int>();
        return intHash(p.first) ^ intHash(p.second);
    }  
};

class Solution {
    
    const int UP = 0;
    const int RIGHT = 1;
    const int DOWN = 2;
    const int LEFT = 3;
    vector<pair<int, int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
    unordered_set<pair<int, int>, PairHash> visited;
    
public:
    
    void moveBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void search(Robot& robot, int curr_x, int curr_y, int dir) {
        visited.insert({curr_x, curr_y});
        robot.clean();
        for (int i = 0; i < 4; i++) {
            int new_dir = (dir+i) % 4;
            int new_x = curr_x + dirs[new_dir].first;
            int new_y = curr_y + dirs[new_dir].second;
            if (!visited.count({new_x, new_y}) and robot.move()) {
                search(robot, new_x, new_y, new_dir);
                moveBack(robot);
            }
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        search(robot, 0, 0, UP);
    }
};











