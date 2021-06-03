/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i++) {
                Node* front = que.front();
                que.pop();
                if (i < len-1) front->next = que.front();
                if (front->left) que.push(front->left);
                if (front->right) que.push(front->right);
            }
        }
        return root;
    }
};


