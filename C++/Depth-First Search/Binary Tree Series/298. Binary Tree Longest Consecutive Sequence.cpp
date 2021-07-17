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
    
    int ans = 0;
    
    int helper(TreeNode* root) {
        if (!root) {
            return 0;
        }
        else {
            int left = helper(root->left);
            int right = helper(root->right);
            int len = 1;
            if (root->left && root->val + 1 == root->left->val) {
                len = max(len, left+1);
            }
            if (root->right && root->val + 1 == root->right->val) {
                len = max(len, right+1);
            }
            ans = max(ans, len);
            return len;
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return ans;
    }
};