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

#include <cmath>

class Solution {
public:
    
    void helper(TreeNode* root, int& res) {
        if (!root->left && !root->right) {
            res += root->val;
            return ;
        }
        if (root->left) {
            root->left->val += root->val*10;
            helper(root->left, res);
        }
        if (root->right) {
            root->right->val += root->val*10;
            helper(root->right, res);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};