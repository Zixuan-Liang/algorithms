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
            return ;
        }
        else {
            vec.push_back(root->val);
            if (targetSum == root->val && !root->left && !root->right) {
                res.push_back(vec);
            }
            else {
                helper(root->left, targetSum-root->val, res, vec);
                helper(root->right, targetSum-root->val, res, vec);
            }
            vec.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> vec;
        helper(root, targetSum, res, vec);
        return res;
    }
};