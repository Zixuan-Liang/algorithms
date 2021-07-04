class Solution {
public:
    
    unordered_map<char, pair<int, int>> dirs{{'U',{-1,0}},{'D',{1,0}},{'L',{0,-1}},{'R',{0,1}}};
    unordered_map<char, char> back{{'U','D'},{'D','U'},{'L','R'},{'R','L'}};
    vector<vector<int>> grid;
    
    void openMap(GridMaster& master, vector<vector<int>>& grid, int curr_x, int curr_y) {
        grid[curr_x][curr_y] = master.isTarget() ? 2 : 1;
        for (auto [dir, dxy] : dirs) {
            int new_x = curr_x + dxy.first;
            int new_y = curr_y + dxy.second;
            if (grid[new_x][new_y] == 0) {
                if (master.canMove(dir)) {
                    master.move(dir);
                    openMap(master, grid, new_x, new_y);
                    master.move(back[dir]);
                }
                else {
                    grid[new_x][new_y] = -1;
                }
            }
        }
    }
    
    int findShortestPath(GridMaster &master) {
        grid = vector<vector<int>>(1000, vector<int>(1000, 0));
        openMap(master, grid, 500, 500);
        // BFS
        queue<pair<int, int>> q;
        q.push({500, 500});
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto xy = q.front();
                q.pop();
                int x = xy.first, y = xy.second;
                if (grid[x][y] == 2) {
                    return ans;
                }
                else if (grid[x][y] == 1) {
                    grid[x][y] = 0;
                    for (auto [dir, dxy] : dirs) {
                        q.push({x + dxy.first, y + dxy.second});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};