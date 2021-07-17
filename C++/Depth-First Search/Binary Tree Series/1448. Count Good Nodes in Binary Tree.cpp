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
#include <algorithm>

class Solution {
    
    int res;
    
public:
    int goodNodes(TreeNode* root) {
        
        res = 0;
        helper(root, INT_MIN);
        return res;
        
    }
    
    void helper(TreeNode* root, int maxVal){
        if (!root) return;
        if (root->val >= maxVal) res++;
        int newMaxVal = max(maxVal, root->val);
        helper(root->left, newMaxVal);
        helper(root->right, newMaxVal);
    }
};