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
    
    pair<int, int> helper(TreeNode* root) {
        if (!root) return {0, 0};
        int inc = 1, dec = 1;
        if (root->left) {
            auto [lInc, lDec] = helper(root->left);
            if (root->val == root->left->val - 1) {
                inc = max(inc, lInc + 1);
            }
            else if (root->val == root->left->val + 1) {
                dec = max(dec, lDec + 1);
            }
        }
        if (root->right) {
            auto [rInc, rDec] = helper(root->right);
            if (root->val == root->right->val - 1) {
                inc = max(inc, rInc + 1);
            }
            else if (root->val == root->right->val + 1) {
                dec = max(dec, rDec + 1);
            }
        }        
        ans = max(ans, inc + dec - 1);
        return {inc, dec};
    }
    
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return ans;
    }
};