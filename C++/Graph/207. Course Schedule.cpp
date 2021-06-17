class Solution {
    
    const int WHITE = 1;
    const int GRAY = 2;
    const int BLACK = 3;
    
public:
    
    void checkCycle(unordered_map<int, vector<int>>& graph, int course, vector<int>& color, bool& isPossible) {
        if (!isPossible) return ;
        color[course] = GRAY;
        if (graph.count(course)) {
            for (int nextCourse : graph[course]) {
                if (color[nextCourse] == WHITE) {
                    checkCycle(graph, nextCourse, color, isPossible);
                }
                else if (color[nextCourse] == GRAY) {
                    isPossible = false;
                }
            }
        }
        color[course] = BLACK;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (auto& p : prerequisites) 
            graph[p[1]].push_back(p[0]);
        vector<int> color(numCourses, WHITE);
        bool isPossible = true;
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == WHITE) {
                checkCycle(graph, i, color, isPossible);
            }
        }
        return isPossible;
    }
};