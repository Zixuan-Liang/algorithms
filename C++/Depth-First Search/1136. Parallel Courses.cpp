class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<vector<int>> graph(N + 1);
        for (auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
        }
        // check if the graph contains a cycle
        vector<string> color(N + 1, "WHITE");
        bool hasCycle = false;
        for (int node = 1; node < N + 1; node++) {
            if (color[node] == "WHITE") checkCycle(node, graph, color, hasCycle);
            if (hasCycle) return -1;
        }

        // if no cycle, return the longest path
        vector<int> visitedLength(N + 1, 0);
        int maxLength = 1;
        for (int node = 1; node < N + 1; node++) {
            int length = dfsMaxPath(node, graph, visitedLength);
            maxLength = max(length, maxLength);
        }
        return maxLength;
    }

private:
    
    void checkCycle(int node, vector<vector<int>>& graph, vector<string>& color, bool& hasCycle) {
        if (hasCycle) return ;
        color[node] = "GRAY";
        for (auto& endNode : graph[node]) {
            if (color[endNode] == "WHITE") {
                checkCycle(endNode, graph, color, hasCycle);
            }
            else if (color[endNode] == "GRAY") {
                hasCycle = true;
            }
        }
        color[node] = "BLACK";
    }

    int dfsMaxPath(int node, vector<vector<int>>& graph,
                   vector<int>& visitedLength) {
        // return the longest path (inclusive)
        if (visitedLength[node] != 0) {
            return visitedLength[node];
        }
        int maxLength = 1;
        for (auto& endNode : graph[node]) {
            int length = dfsMaxPath(endNode, graph, visitedLength);
            maxLength = max(length + 1, maxLength);
        }
        // store it
        visitedLength[node] = maxLength;
        return maxLength;
    }
};