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
    
    bool helper(TreeNode* root) {
        if (!root) return true;
        bool lPrune = helper(root->left);
        bool rPrune = helper(root->right);
        if (lPrune) root->left = nullptr;
        if (rPrune) root->right = nullptr;
        if (lPrune && rPrune && root->val == 0) 
            return true;
        else
            return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool prune = helper(root);
        if (prune)
            return nullptr;
        else
            return root;
    }
};