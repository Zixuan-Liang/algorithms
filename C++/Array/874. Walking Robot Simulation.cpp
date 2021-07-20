struct PairHash {
    size_t operator()(const pair<int, int>& p)const {
        auto intHash = hash<int>();
        return intHash(p.first) ^ intHash(p.second);
    }  
};

class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, PairHash> lookup;
        for (auto obstacle : obstacles) {
            lookup.insert({obstacle[0], obstacle[1]});
        }
        vector<vector<int>> move = {{0,1},{1,0},{0,-1},{-1,0}};
        int direction = 0; // 0 : north, 1: east, 2: south, 3: west
        int x = 0, y = 0;
        int ans = 0;
        for (int command : commands) {
            if (command == -2) {
                direction = direction == 0 ? 3 : direction - 1;
            }
            else if (command == -1) {
                direction = direction == 3 ? 0 : direction + 1;
            }
            else {
                int dx = move[direction][0], dy = move[direction][1];
                for (int i = 0; i < command; i++) {
                    if (!lookup.count({x + dx, y + dy})) {
                        x += dx;
                        y += dy;
                        ans = max(ans, x * x + y * y);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
    }

};