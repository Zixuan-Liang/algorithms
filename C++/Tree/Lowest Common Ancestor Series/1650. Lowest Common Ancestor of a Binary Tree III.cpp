/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> pPath, qPath;
        while (p) {
            pPath.push_back(p);
            p = p->parent;
        }
        while (q) {
            qPath.push_back(q);
            q = q->parent;
        }
        int i = pPath.size() - 1, j = qPath.size() - 1;
        while (i >= 0 && j >= 0 && pPath[i] == qPath[j]) {
            i--, j--;
        }
        return pPath[i+1];
    }
};