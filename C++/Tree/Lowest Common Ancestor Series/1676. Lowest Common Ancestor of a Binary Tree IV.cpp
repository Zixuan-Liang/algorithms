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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> nodeSet;
        for (TreeNode* node : nodes) {
            nodeSet.insert(node);
        }
        return findLCA(root, nodeSet);
    }
    
    
    TreeNode* findLCA(TreeNode* root, unordered_set<TreeNode*>& nodeSet) {
        if (!root) {
            return nullptr;
        }
        if (nodeSet.count(root)) {
            return root;
        }
        TreeNode* l = findLCA(root->left, nodeSet);
        TreeNode* r = findLCA(root->right, nodeSet);
        if (l && r) {
            return root;
        }
        else if (l) {
            return l;
        }
        else if (r) {
            return r;
        }
        else {
            return nullptr;
        }
    }
};