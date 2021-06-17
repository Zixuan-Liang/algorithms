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
            return {0, 0, 999999};
        }
        // 0: Strict ST; All nodes below this are covered, but not this one
        // 1: Normal ST; All nodes below and incl this are covered - no camera
        // 2: Placed camera; All nodes below this are covered, plus camera here
        vector<int> L = helper(root->left);
        vector<int> R = helper(root->right);
        int mL12 = min(L[1], L[2]);
        int mR12 = min(R[1], R[2]);
        int d0 = L[1] + R[1];
        int d1 = min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + min(L[0], mL12) + min(R[0], mR12);
        return {d0, d1, d2};
    }
    
    int minCameraCover(TreeNode* root) {
        vector<int> res = helper(root);
        return min(res[1], res[2]);
    }
};