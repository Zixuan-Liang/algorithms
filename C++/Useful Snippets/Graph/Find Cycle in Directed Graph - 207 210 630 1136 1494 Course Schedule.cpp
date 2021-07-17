#include <unordered_map>

const int WHITE = 1;
const int GRAY = 2;
const int BLACK = 3;

// 图有n个点
// graph：哈希表，包含了图的信息：键：节点，值：包含节点指向的邻接点的数组
unordered_map<int, vector<int>> graph;

// 用3种颜色记录访问节点访问状态以找出环，白：未访问，灰：访问中，黑：已访问
vector<int> color(n, WHITE);

// 初始化
bool noCycle = true; // 一开始假设没有环
for (int i = 0; i < n; i++) {
    if (color[i] == WHITE) { // 对于每个还没访问的点，从该点出发查找环
        checkCycle(graph, i, color, noCycle);
    }
}

void checkCycle(unordered_map<int, vector<int>>& graph, int node, vector<int>& color, bool& noCycle) {
    if (!noCycle) return ; // 已经找到了一个环，直接返回
    color[node] = GRAY; // 将当前点设置为访问中
    if (graph.count(node)) {
        for (int nextNode : graph[node]) {
            if (color[nextNode] == WHITE) { // 对未访问的邻接点进行DFS
                checkCycle(graph, nextNode, color, noCycle);
            }
            else if (color[nextNode] == GRAY) { // 如果邻接点的状态是“访问中”，说明有环
                noCycle = false;
            }
        }
    }
    color[node] = BLACK; // DFS完了将当前点设为“已访问”
}