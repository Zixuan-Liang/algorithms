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
    
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& vec) {
        if (!root) {
            return;
        }
        else if (!root->left && !root->right) {
            if (targetSum == root->val) {
                vec.push_back(root->val);
                res.push_back(vec);
            }
        }
        else {
            vec.push_back(root->val);
            vector<int> leftVec = vec, rightVec = vec;
            helper(root->left, targetSum-root->val, res, leftVec);
            helper(root->right, targetSum-root->val, res, rightVec);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> vec;
        helper(root, targetSum, res, vec);
        return res;
    }
};