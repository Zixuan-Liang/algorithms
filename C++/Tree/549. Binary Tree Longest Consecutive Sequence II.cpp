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
    
    vector<int> helper(TreeNode* root, int& res) {
        int inc, dec;
        if (!root) {
            inc = 0;
            dec = 0;
        }
        else if (!root->left && !root->right) {
            inc = 1;
            dec = 1;
        }
        else {
            vector<int> left = helper(root->left, res), right = helper(root->right, res);
            
            bool lInc = root->left && root->val == root->left->val - 1;
            bool rInc = root->right && root->val == root->right->val - 1;
            bool lDec = root->left && root->val == root->left->val + 1;
            bool rDec = root->right && root->val == root->right->val + 1;
            
            int lIncLen = (lInc) ? left[0]+1 : 1;
            int rIncLen = (rInc) ? right[0]+1 : 1;
            
            int lDecLen = (lDec) ? left[1]+1 : 1;
            int rDecLen = (rDec) ? right[1]+1 : 1;
            
            inc = max(lIncLen, rIncLen);
            dec = max(lDecLen, rDecLen);
            
            if (lInc && rDec) res = max(res, left[0]+right[1]+1);
            if (lDec && rInc) res = max(res, left[1]+right[0]+1);
        }
        res = max({res, inc, dec});
        return {inc, dec};
    }
    
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};