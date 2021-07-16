/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> que;
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*> memo;
        if (node) {
            que.push(node);
            visited.insert(node);
        }
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                Node* front = que.front();
                Node* newNode = new Node(front->val);
                memo[front] = newNode;
                for (auto& n : front->neighbors) {
                    if (visited.find(n) == visited.end()) {
                        que.push(n);
                        visited.insert(n);
                    }
                }
                que.pop();
            }
        }
        
        visited.clear();
        if (node) {
            que.push(node);
            visited.insert(node);
        }
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                Node* front = que.front();        
                for (auto& n : front->neighbors) {
                    memo[front]->neighbors.push_back(memo[n]);
                    if (visited.find(n) == visited.end()) {
                        que.push(n);
                        visited.insert(n);
                    }
                }
                que.pop();
            }
        }
        
        return memo[node];
    }
};