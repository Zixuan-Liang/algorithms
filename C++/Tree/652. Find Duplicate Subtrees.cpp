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
    
    string traverse(TreeNode* root, unordered_map<string, vector<TreeNode*>>& umap) {
        if (!root) return "null";
        string s = to_string(root->val) + '-' + traverse(root->left, umap) + '-' + traverse(root->right, umap);
        umap[s].push_back(root);
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> umap;
        traverse(root, umap);
        vector<TreeNode*> res;
        for (auto& item : umap) {
            if (item.second.size() > 1) {
                res.push_back(item.second[0]);
            }
        }
        return res;
    }
};
