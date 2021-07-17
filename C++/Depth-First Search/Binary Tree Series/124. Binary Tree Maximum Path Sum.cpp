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
    
    int helper(TreeNode* root, int& res) {
        int maxLeft = root->left ? max(0, helper(root->left, res)) : 0;
        int maxRight = root->right ? max(0, helper(root->right, res)) : 0;
        int maxRoot = root->val + max(maxLeft, maxRight);
        res = max(res, root->val + maxLeft + maxRight);
        return maxRoot;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};