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
        int left = 0, right = pow(2, d) - 1;
        for (int i = 0; i < d; i++) {
            int pivot = (left + right) / 2;
            if (idx <= pivot) {
                root = root->left;
                right = pivot;
            }
            else {
                root = root->right;
                left = pivot + 1;
            }
        }
        return root != nullptr;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int d = computeDepth(root);
        if (d == 0) return 1;
        
        int left = 1, right = pow(2, d) - 1;
        while (left <= right) {
            int pivot = (left + right) / 2;
            if (exists(pivot, d, root)) {
                left = pivot + 1;
            }
            else {
                right = pivot - 1;
            }
        }
        
        return pow(2, d) - 1 + left;
    }
};