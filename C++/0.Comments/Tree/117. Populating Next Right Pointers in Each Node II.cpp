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
    
    void processChild(Node* childNode, Node*& next_lev_rightmost, Node*& leftMost) {
        if (childNode) {
            if (next_lev_rightmost) {
                next_lev_rightmost->next = childNode; // 建立下一层“链表”
            }
            else {
                leftMost = childNode; // 找到了下一层的最左点！
            }
            next_lev_rightmost = childNode; // 更新下一层的当前点
        }
    }
    
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        
        // 从根节点开始
        Node* leftMost = root;
        
        // 当我们访问到最后一层的时候结束
        while (leftMost) {
            // 当前层视作链表，遍历它，next_lev_rightmost是下一层的当前点，curr是当前层的当前点
            Node* next_lev_rightmost = nullptr, * curr = leftMost;
            leftMost = NULL; // 如果接下来的循环没有给leftMost赋值，说明下一层已经没有节点，跳出大循环
            while (curr) { 
                processChild(curr->left, next_lev_rightmost, leftMost); // 根据当前层当前点的左右孩子，适时修改下一层当前点、下一层最左点
                processChild(curr->right, next_lev_rightmost, leftMost);
                curr = curr->next; // 遍历当前层
            }       
        }
        return root;
    }
};