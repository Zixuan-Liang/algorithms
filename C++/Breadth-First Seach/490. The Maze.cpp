class Solution {
    
public:
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> adjs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = 1;
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if (curr == destination)
                return true;
            for (auto [dx, dy] : adjs) {
                int x = curr[0] + dx;
                int y = curr[1] + dy;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dx;
                    y += dy;
                }
                x -= dx; y -= dy;
                if (visited[x][y] == 0) {
                    q.push({x, y});
                    visited[x][y] = 1;
                }
            }
        }
        return false;
        
    }
};