/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) { // sanity check
            return nullptr;
        }
        TreeNode* node = findLCA(root, p, q);
        if (node == p) {
            return findLCA(p, q, q) ? node : nullptr;
        }
        else if (node == q) {
            return findLCA(q, p, p) ? node : nullptr;
        }
        else {
            return node;
        }
    }
    
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) {
            return root;
        }
        TreeNode* l = findLCA(root->left, p, q);
        TreeNode* r = findLCA(root->right, p, q);
        if (l && r) {
            return root;
        }
        else if (l) {
            return l;
        }
        else if (r) {
            return r;
        }
        else {
            return nullptr;
        }
    }
    
};
  