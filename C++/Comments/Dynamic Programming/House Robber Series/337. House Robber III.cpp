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
    
    vector<int> helper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        vector<int> L = helper(root->left);
        vector<int> R = helper(root->right);
        int d1 = root->val + L[1] + R[1];
        int d2 = max(L[0], L[1]) + max(R[0], R[1]);
        return {d1, d2}; // {rob curr node, no rob curr node}
    }
    
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
};