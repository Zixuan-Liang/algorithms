/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int computeDepth(TreeNode* root) {
        int d = 0;
        while (root->left) {
            root = root->left;
            d++;
        }
        return d;
    }
    
    bool exists(int idx, int d, TreeNode* root) {
        int left = 0, right = pow(2, d) - 1; // 循环不变量，答案可能存在于[left, right]
        for (int i = 0; i < d; i++) {
            int pivot = (left + right) / 2;
            if (idx <= pivot) { // 往左查找，保持循环不变量：答案可能存在于[left, right]
                root = root->left;
                right = pivot;
            }
            else { // 往右查找，保持循环不变量：答案可能存在于[left, right]
                root = root->right;
                left = pivot + 1;
            }
        }
        return root != nullptr; // 检查答案是否存在
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int d = computeDepth(root);
        if (d == 0) return 1;
        // Y代表存在，N代表不存在
        // YYY...YYYNNN... 查找第一个不存在的index
        int left = 1, right = pow(2, d);
        while (left < right) { // 循环不变量，答案必存在于[left, right]
            int pivot = left + (right - left) / 2;
            if (exists(pivot, d, root)) { // 保持循环不变量：答案必存在于[left, right]
                left = pivot + 1;
            }
            else {
                right = pivot;
            }
        }
        return pow(2, d) - 1 + left; // 循环打破，left=right，left就是第一个不存在的index，即为最后一层的节点数
    }
};