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

// 此算法避免使用队列进行BFS，节省了O(n)的空间
// 复杂度：树的节点数为n
// 时间：O(n)，空间：O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        
        // 从根节点开始
        Node* leftMost = root;
        
        // 当我们访问到最后一层的时候结束
        while (leftMost->left) {
            // 当前层视作链表，遍历它
            Node* head = leftMost;
            while (head) { 
                head->left->next = head->right; // 左孩子指向右孩子
                if (head->next) {
                    head->right->next = head->next->left; // 右孩子指向下一个点的左孩子
                }
                head = head->next;
            }       
            leftMost = leftMost->left;
        }
        return root;
    }
};