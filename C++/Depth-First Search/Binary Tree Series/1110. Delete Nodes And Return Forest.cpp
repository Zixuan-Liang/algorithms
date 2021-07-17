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
    
    TreeNode* helper(TreeNode* root, unordered_set<int>& toDelete, vector<TreeNode*>& ans, bool isRoot) {
        if (!root) return nullptr;
        bool deleted = toDelete.count(root->val);
        root->left = helper(root->left, toDelete, ans, deleted);
        root->right = helper(root->right, toDelete, ans, deleted);
        if (isRoot && !deleted) {
            ans.push_back(root);
        }
        return deleted ? nullptr : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete;
        for (int num : to_delete) {
            toDelete.insert(num);
        }
        vector<TreeNode*> ans;
        helper(root, toDelete, ans, true);
        return ans;
    }
};