#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;

        if (k > m+n-2 ) return m+n-2;

        queue<vector<int>> q;
        q.push({0,0,0,0});
        set<vector<int>> visited;
        vector<vector<int>> neighbors = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            vector<int> front = q.front();
            int i = front[0], j = front[1], removed = front[2], pathLen = front[3];
            q.pop();
            for (auto& neighbor : neighbors) {
                int ni = i + neighbor[0], nj = j + neighbor[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (grid[ni][nj] == 1 && removed < k && visited.find({ni, nj, removed+1}) == visited.end()) {
                        visited.insert({ni, nj, removed+1});
                        q.push({ni, nj, removed+1, pathLen+1});
                    }
                    if (grid[ni][nj] == 0 && visited.find({ni, nj, removed}) == visited.end()) {
                        if (ni == m-1 && nj == n-1) {
                            return pathLen + 1;
                        }
                        visited.insert({ni, nj, removed});
                        q.push({ni, nj, removed, pathLen+1});
                    }                    
                }

            }
        }
        
        return -1;
    }
};