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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};
        vector<string> lPaths = binaryTreePaths(root->left);
        vector<string> rPaths = binaryTreePaths(root->right);
        vector<string> res;
        for (string& path : lPaths) {
            res.push_back(to_string(root->val) + "->" + path);
        }
        for (string& path : rPaths){
            res.push_back(to_string(root->val) + "->" + path);
        }
        return res;
    }
};