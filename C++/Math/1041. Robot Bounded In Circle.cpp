class Solution {
public:
    bool isRobotBounded(string instructions) {
        unordered_map<string, string> turn_left = {{"N", "W"},{"W", "S"},{"S", "E"},{"E", "N"}};
        unordered_map<string, string> turn_right = {{"N", "E"},{"E", "S"},{"S", "W"},{"W", "N"}};
        unordered_map<string, vector<int>> move = {{"N", {0,1}},{"E", {1,0}},{"S", {0,-1}},{"W", {-1,0}}};
        int turn_count = 0;
        vector<int> position = {0, 0};
        string direction = "N";
        for (char instruction : instructions) {
            if (instruction == 'L') {
                direction = turn_left[direction];
                turn_count++;
            }
            else if (instruction == 'R') {
                direction = turn_right[direction];
                turn_count--;
            }
            else {
                position[0] += move[direction][0];
                position[1] += move[direction][1];
            }
        }
        if (turn_count % 4 == 0 && position != vector<int>{0, 0}) { // 最后方向不变，位置非原点，则不能闭环
            return false;
        }
        else {
            return true;
        }
    }
};