struct Cell {
    int row;
    int col;
    int height;
    Cell(int r, int c, int h): row(r), col(c), height(h) {}
};

struct CompareCell {
    bool operator()(const Cell& a, const Cell& b) {
        return a.height > b.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        priority_queue<Cell, vector<Cell>, CompareCell> q;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // Add all cells which are on borders to the queue.
        for (int i = 0; i < m; i++) {
            visited[i][0] = 1;
            visited[i][n-1] = 1;
            q.push(Cell(i, 0, heights[i][0]));
            q.push(Cell(i, n-1, heights[i][n-1]));
        }
        for (int i = 0; i < n; i++) {
            visited[0][i] = 1;
            visited[m-1][i] = 1;
            q.push(Cell(0, i, heights[0][i]));
            q.push(Cell(m-1, i, heights[m-1][i]));
        }
        // From the borders, pick the shortest cell visited and check its neighbors
        // If the neighbor is shorter, collect the water it can trap and update its height as its height plus the water trapped
        // Add all its neighbors to the queue
        vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int res = 0;
        while (!q.empty()) {
            Cell cell = q.top();
            q.pop();
            for (auto& [dr, dc] : dirs) {
                int row = cell.row + dr;
                int col = cell.col + dc;
                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    visited[row][col] = 1;
                    res += max(0, cell.height - heights[row][col]);
                    q.push(Cell(row, col, max(heights[row][col], cell.height)));
                }
            }
        }
        return res;
    }
};