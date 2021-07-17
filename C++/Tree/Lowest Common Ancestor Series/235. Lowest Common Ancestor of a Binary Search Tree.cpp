/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 可以直接用236的答案，不过这样需要搜索左右子树。可以利用到二叉搜索树的性质，每次只搜左或右
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root || root==p || root==q) {
//             return root;
//         }
//         TreeNode* l = lowestCommonAncestor(root->left, p, q);
//         TreeNode* r = lowestCommonAncestor(root->right, p, q);
//         if (l && r) {
//             return root;
//         }
//         else if (l) {
//             return l;
//         }
//         else if (r) {
//             return r;
//         }
//         else {
//             return nullptr;
//         }
//     }
// };

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return root;
        }
    }
    
};