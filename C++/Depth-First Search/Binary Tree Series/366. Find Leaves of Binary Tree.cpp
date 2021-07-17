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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        helper(ret,root);
        return ret;
    }
    
    
    int helper(vector<vector<int>>& dp,TreeNode *root){
        if(root == nullptr)
            return -1;
        int l = helper(dp,root->left);
        int r = helper(dp,root->right);
        int h = max(l,r) + 1;
        if(h>=dp.size())
            dp.push_back(vector<int>());
        dp[h].push_back(root->val);
        return h;
    }
};