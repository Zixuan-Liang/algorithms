/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> memo;
        Node* p = head;
        while (p) {
            Node* newNode = new Node(p->val);
            memo[p] = newNode;
            p = p->next;
        }
        p = head;
        while (p) {
            if (p->next) memo[p]->next = memo[p->next];
            if (p->random) memo[p]->random = memo[p->random];
            p = p->next;
        }
        return memo[head];
    }
};