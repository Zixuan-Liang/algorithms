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
    
    pair<TreeNode*, TreeNode*> helper(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return {root, root};
        TreeNode* left = root->left, * right = root->right;
        auto leftRes = helper(left);
        auto rightRes = helper(right);
        
        root->left = nullptr;
        if (get<0>(leftRes)) {
            root->right = get<0>(leftRes);
            get<1>(leftRes)->right = get<0>(rightRes);
        }
        
        if (get<1>(rightRes)) return {root, get<1>(rightRes)};
        else return {root, get<1>(leftRes)};
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};