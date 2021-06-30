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
                
        auto l = helper(root->left);
        auto r = helper(root->right);
        
        TreeNode* lHead = l.first, * lTail = l.second;
        TreeNode* rHead = r.first, * rTail = r.second;
        
        root->left = nullptr;
        
        if (lHead) {
            root->right = lHead;
            lTail->right = rHead;
        }
        
        if (rTail) return {root, rTail};
        else return {root, lTail};
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};