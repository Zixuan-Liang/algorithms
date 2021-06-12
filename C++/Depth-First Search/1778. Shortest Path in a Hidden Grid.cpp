/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
    
    int g[1000][1000] = {};
    vector<pair<char, array<int, 2>>> dirs{{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};
    
public:
    
    void map(GridMaster &master, int x, int y, char back) {
        g[x][y] = master.isTarget() ? 2 : 1;
        for (auto i = 0; i < dirs.size(); ++i) {
            auto& [d, dxy] = dirs[i];
            if (g[x + dxy[0]][y + dxy[1]] == 0) {
                if (master.canMove(d)) {
                    master.move(d);
                    map(master, x + dxy[0], y + dxy[1], dirs[i % 2 ? i - 1 : i + 1].first);
                }
                else 
                    g[x + dxy[0]][y + dxy[1]] = -1;
            }
        }
        master.move(back);
    }
    
    int findShortestPath(GridMaster &master) {
        int x = 500, y = 500, cnt = 0;
        map(master, x, y, 'U');
        vector<pair<int, int>> q{{x, y}};
        while (!q.empty()) {
            vector<pair<int, int>> q1;
            for (auto [x, y] : q) {
                if (g[x][y] == 2)
                    return cnt;
                if (g[x][y] == 1) {
                    g[x][y] = -1;
                    for (auto [_, dd] : dirs)
                        q1.push_back({x + dd[0], y + dd[1]});
                }
            }
            ++cnt;
            swap(q, q1);
        }
        return -1;
    }
    
};