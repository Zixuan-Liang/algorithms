#include <unordered_map>
#include <set>
#include <vector>

// E: 边数，V：节点数，O(VlogV + ElogV)

// 输入：connection[[node1, node2, weight], ...]
// Power Grid: minimum spanning tree, Amazon OA，保留一些边使得所有边的权重和最小，所有点保持连接：最小生成树
vector<vector<int>> minimum_spanning_tree(vector<vector<int>>& connection) {
    unordered_map<int, unordered_map<int, int>> adjs; // 建立邻接哈希表
    for (auto edge : connection) {
        adjs[edge[0]][edge[1]] = edge[2];
        adjs[edge[1]][edge[0]] = edge[2];
    }
    vector<vector<int>> keys(adjs.size()); // 初始化每个点：权重INT_MAX，ID，父节点-1
    for (int i = 0; i < keys.size(); i++) {
        keys[i] = {INT_MAX, i, -1}; // key value, node id, parent
    }
    keys[0][0] = 0; // 第一个点的权重设为0，从第一个点开始（可以从任意点开始）
    set<vector<int>> pq(keys.begin(), keys.end()); // 优先队列（用set实现方便删除）(建立优先队列的复杂度：可能是O(V)或者O(VlogV)？不清楚c++的set construct是怎样的)
    unordered_set<int> tree; // 哈希表保存已建立的树节点 (也可以用数组保存0，1状态表示)
    vector<vector<int>> ans; // 输出答案：保留的边数组
    while (!pq.empty()) { // 循环在优先队列为空，即所有点都已经添加到树的时候终止，这里循环的复杂度O(VlogV)
        vector<int> node = *pq.begin(); // 将权重最小的点出队
        pq.erase(pq.begin());
        if (node[2] != -1) { // 将该点和父节点添加到树节点哈希表，将边添加到答案数组
            int s = min(node[1], node[2]), l = max(node[1], node[2]); // 这里比较一下id大小，小点放前面，大点放后面
            ans.push_back({s, l, adjs[s][l]});
            tree.insert(s);
            tree.insert(l);
        }
        for (auto [neighbor_id, weight] : adjs[node[1]]) { // 这里循环的复杂度O(ElogV)，因为一共有E条边，所以这个循环执行O(E)次，循环里操作优先队列O(logV)
            if (!tree.count(neighbor_id) && weight < keys[neighbor_id][0]) { // 如果邻居还没加到树中，而且边的值小于邻居现在的权重，则更新邻居的权重和父节点，更新优先队列
                pq.erase(keys[neighbor_id]); // 删除旧值
                keys[neighbor_id][0] = weight;
                keys[neighbor_id][2] = node[1];
                pq.insert(keys[neighbor_id]); // 插入新值
            }
        }
    }
    return ans;
}
